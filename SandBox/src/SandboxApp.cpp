#include <VitDragonEngine.h>

#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include "glm/gtc/type_ptr.hpp"

#include "Platform/OpenGL/OpenGLShader.h"

class ExampleLayer : public VitDragonEngine::Layer{
public:
	ExampleLayer()
		: Layer( "Example" ), m_Camera( -1.6f, 1.6, -0.9, 0.9 ), m_CameraPosition( 0.0f ){

		m_VertexArray.reset( VitDragonEngine::VertexArray::Create() );

		float vertices[ 3 * 7 ] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
			 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f,
		};

		VitDragonEngine::Ref <VitDragonEngine::VertexBuffer> vertexBuffer;
		vertexBuffer.reset( VitDragonEngine::VertexBuffer::Create( vertices, sizeof( vertices ) ) );

		VitDragonEngine::BufferLayout layout = {
			{ VitDragonEngine::ShaderDataType::Float3, "a_Position"},
			{ VitDragonEngine::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout( layout );
		m_VertexArray->AddVertexBuffer( vertexBuffer );

		unsigned int indices[ 3 ] = { 0, 1, 2 };
		VitDragonEngine::Ref <VitDragonEngine::IndexBuffer> indexBuffer;
		indexBuffer.reset( VitDragonEngine::IndexBuffer::Create( indices, sizeof( indices ) / sizeof( uint32_t ) ) );
		m_VertexArray->SetIndexBuffer( indexBuffer );


		m_SquareVA.reset( VitDragonEngine::VertexArray::Create() );
		float squareVertices[ 5 * 4 ] = {
			-0.5f, -0.5f, 0.0f,		0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f,		1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f,		1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f,		0.0f, 1.0f
		};
		VitDragonEngine::Ref<VitDragonEngine::VertexBuffer> squareVB;
		squareVB.reset( VitDragonEngine::VertexBuffer::Create( squareVertices, sizeof( squareVertices ) ) );
		squareVB->SetLayout( {
			{ VitDragonEngine::ShaderDataType::Float3, "a_Position"},
			{ VitDragonEngine::ShaderDataType::Float2, "a_TextCoord"}
			} );
		m_SquareVA->AddVertexBuffer( squareVB );

		unsigned int squareIndices[ 6 ] = { 0, 1, 2, 2, 3, 0 };
		VitDragonEngine::Ref<VitDragonEngine::IndexBuffer> squareID;
		squareID.reset( VitDragonEngine::IndexBuffer::Create( squareIndices, sizeof( squareIndices ) / sizeof( uint32_t ) ) );
		m_SquareVA->SetIndexBuffer( squareID );

		std::string vertexSrc = R"(
			#version 330 core	
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main(){
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core	
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main(){
				color = vec4(v_Position * 0.5 + 0.5, 1.0);
				color = v_Color;
			}
		)";

		m_Shader.reset( VitDragonEngine::Shader::Create( vertexSrc, fragmentSrc ) );

		std::string FlatShaderVertexSrc = R"(
			#version 330 core	
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main(){
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string FlatColorShaderFragmentSrc = R"(
			#version 330 core	
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			uniform vec3 u_Color;

			void main(){
				color = vec4(u_Color, 1.0f);
			}
		)";

		m_FlatColorShader.reset(VitDragonEngine::Shader::Create( FlatShaderVertexSrc, FlatColorShaderFragmentSrc ) );



		std::string TextureShaderVertexSrc = R"(
			#version 330 core	
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec2 a_TextCoord;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec2 v_TextCoord;

			void main(){
				v_TextCoord = a_TextCoord;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);
			}
		)";

		std::string TextureShaderFragmentSrc = R"(
			#version 330 core	
			
			layout(location = 0) out vec4 color;

			in vec2 v_TextCoord;

			uniform sampler2D u_Texture;

			void main(){
				color = texture(u_Texture, v_TextCoord);
			}
		)";

		m_TextureShader.reset( VitDragonEngine::Shader::Create( TextureShaderVertexSrc, TextureShaderFragmentSrc ) );
		
		m_Texture = ( VitDragonEngine::Texture2D::Create( "assets/textures/Checkerboard.png" ) );
		m_ChernoLogoTexture = ( VitDragonEngine::Texture2D::Create( "assets/textures/ChernoLogo.png" ) );

		std::dynamic_pointer_cast< VitDragonEngine::OpenGLShader >( m_TextureShader )->Bind();
		std::dynamic_pointer_cast< VitDragonEngine::OpenGLShader >( m_TextureShader )->UploadUniformInt( "u_Texture", 0 );
	}

	void OnUpdate(VitDragonEngine::TimeStep ts) override{

		if( VitDragonEngine::Input::IsKeyPressed(VDE_KEY_LEFT ) )
			m_CameraPosition.x -= m_CameraMoveSpeed * ts;

		else if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_RIGHT ) )
			m_CameraPosition.x += m_CameraMoveSpeed * ts;

		if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_UP ) )
			m_CameraPosition.y += m_CameraMoveSpeed * ts;

		else if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_DOWN ) )
			m_CameraPosition.y -= m_CameraMoveSpeed * ts;

		
		if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_A ) )
			m_CameraRotation += m_CameraRotationSpeed * ts;

		else if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_D ) )
			m_CameraRotation -= m_CameraRotationSpeed * ts;

		VitDragonEngine::RenderCommand::SetClearColor( { 0.1f, 0.1f, 0.1f, 1 } );
		VitDragonEngine::RenderCommand::Clear();

		m_Camera.SetPosition( m_CameraPosition );
		m_Camera.SetRotation( m_CameraRotation );

		VitDragonEngine::Renderer::BeginScene( m_Camera );

		static glm::mat4 scale = glm::scale( glm::mat4( 1.0f ), glm::vec3( 0.1f ) );

		std::dynamic_pointer_cast< VitDragonEngine::OpenGLShader >( m_FlatColorShader )->Bind();
		std::dynamic_pointer_cast< VitDragonEngine::OpenGLShader >( m_FlatColorShader )->UploadUniformFloat3( "u_Color", m_SquareColor );

		for( int x = 0; x < 20; x++ ){
			for( int y = 0; y < 20; y++ ){
				glm::vec3 pos( x * 0.11f, y * 0.11f, 0.0f );
				glm::mat4 transform = glm::translate( glm::mat4( 1.0f ), pos) * scale;
				VitDragonEngine::Renderer::Submit( m_FlatColorShader, m_SquareVA, transform  );
			}
		}

		m_Texture->Bind();
		VitDragonEngine::Renderer::Submit( m_TextureShader, m_SquareVA, glm::scale( glm::mat4( 1.0f ), glm::vec3( 1.5f ) ) );
		m_ChernoLogoTexture->Bind();
		VitDragonEngine::Renderer::Submit( m_TextureShader, m_SquareVA, glm::scale( glm::mat4( 1.0f ), glm::vec3( 1.5f ) ) );

		// Triangle
		// VitDragonEngine::Renderer::Submit( m_Shader, m_VertexArray );

		VitDragonEngine::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override{
		ImGui::Begin( "Settings" );
		ImGui::ColorEdit3( "Square Color", glm::value_ptr( m_SquareColor ) );
		ImGui::End();
	}

	void OnEvent( VitDragonEngine::Event &event ) override{
		
	}

private:
	VitDragonEngine::Ref<VitDragonEngine::Shader> m_Shader;
	VitDragonEngine::Ref<VitDragonEngine::VertexArray> m_VertexArray;

	VitDragonEngine::Ref<VitDragonEngine::Shader> m_FlatColorShader, m_TextureShader;
	VitDragonEngine::Ref<VitDragonEngine::VertexArray> m_SquareVA;

	VitDragonEngine::Ref<VitDragonEngine::Texture2D> m_Texture, m_ChernoLogoTexture;

	VitDragonEngine::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	float m_CameraMoveSpeed = 5.0f;
	
	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 180.0f;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class SandBox : public VitDragonEngine::Application{
public:
	SandBox(){
		PushLayer( new ExampleLayer() );
	}

	~SandBox(){

	}

};

VitDragonEngine::Application *VitDragonEngine::CreateApplication(){
	return new SandBox();
}