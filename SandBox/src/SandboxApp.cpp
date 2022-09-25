#include <VitDragonEngine.h>

#include "imgui/imgui.h"

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

		std::shared_ptr <VitDragonEngine::VertexBuffer> vertexBuffer;
		vertexBuffer.reset( VitDragonEngine::VertexBuffer::Create( vertices, sizeof( vertices ) ) );

		VitDragonEngine::BufferLayout layout = {
			{ VitDragonEngine::ShaderDataType::Float3, "a_Position"},
			{ VitDragonEngine::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout( layout );
		m_VertexArray->AddVertexBuffer( vertexBuffer );

		unsigned int indices[ 3 ] = { 0, 1, 2 };
		std::shared_ptr <VitDragonEngine::IndexBuffer> indexBuffer;
		indexBuffer.reset( VitDragonEngine::IndexBuffer::Create( indices, sizeof( indices ) / sizeof( uint32_t ) ) );
		m_VertexArray->SetIndexBuffer( indexBuffer );


		m_SquareVA.reset( VitDragonEngine::VertexArray::Create() );
		float squareVertices[ 3 * 4 ] = {
			-0.75f, -0.75f, 0.0f,
			 0.75f, -0.75f, 0.0f,
			 0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};
		std::shared_ptr<VitDragonEngine::VertexBuffer> squareVB;
		squareVB.reset( VitDragonEngine::VertexBuffer::Create( squareVertices, sizeof( squareVertices ) ) );
		squareVB->SetLayout( {
			{ VitDragonEngine::ShaderDataType::Float3, "a_Position"}
			} );
		m_SquareVA->AddVertexBuffer( squareVB );

		unsigned int squareIndices[ 6 ] = { 0, 1, 2, 2, 3, 0 };
		std::shared_ptr<VitDragonEngine::IndexBuffer> squareID;
		squareID.reset( VitDragonEngine::IndexBuffer::Create( squareIndices, sizeof( squareIndices ) / sizeof( uint32_t ) ) );
		m_SquareVA->SetIndexBuffer( squareID );

		std::string vertexSrc = R"(
			#version 330 core	
			
			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;
			out vec4 v_Color;

			void main(){
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
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

		m_Shader.reset( new VitDragonEngine::Shader( vertexSrc, fragmentSrc ) );

		std::string BlueVertex = R"(
			#version 330 core	
			
			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;

			out vec3 v_Position;

			void main(){
				v_Position = a_Position;
				gl_Position = u_ViewProjection * vec4(a_Position, 1.0);
			}
		)";

		std::string BlueFragment = R"(
			#version 330 core	
			
			layout(location = 0) out vec4 color;

			in vec3 v_Position;

			void main(){
				color = vec4(0.2, 0.3, 0.8, 1.0);
			}
		)";

		m_BlueShader.reset( new VitDragonEngine::Shader( BlueVertex, BlueFragment ) );
	
	}

	void OnUpdate() override{

		if( VitDragonEngine::Input::IsKeyPressed(VDE_KEY_LEFT ) )
			m_CameraPosition.x -= m_CameraMoveSpeed;

		else if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_RIGHT ) )
			m_CameraPosition.x += m_CameraMoveSpeed;

		if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_UP ) )
			m_CameraPosition.y += m_CameraMoveSpeed;

		else if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_DOWN ) )
			m_CameraPosition.y -= m_CameraMoveSpeed;

		
		if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_A ) )
			m_CameraRotation += m_CameraRotationSpeed;

		else if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_D ) )
			m_CameraRotation -= m_CameraRotationSpeed;




		VitDragonEngine::RenderCommand::SetClearColor( { 0.1f, 0.1f, 0.1f, 1 } );
		VitDragonEngine::RenderCommand::Clear();

		m_Camera.SetPosition( m_CameraPosition );
		m_Camera.SetRotation( m_CameraRotation );

		VitDragonEngine::Renderer::BeginScene( m_Camera );

		VitDragonEngine::Renderer::Submit( m_BlueShader, m_SquareVA );

		VitDragonEngine::Renderer::Submit( m_Shader, m_VertexArray );

		VitDragonEngine::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override{

	}

	void OnEvent( VitDragonEngine::Event &event ) override{
		
	}

private:
	std::shared_ptr<VitDragonEngine::Shader> m_Shader;
	std::shared_ptr<VitDragonEngine::VertexArray> m_VertexArray;

	std::shared_ptr<VitDragonEngine::Shader> m_BlueShader;
	std::shared_ptr<VitDragonEngine::VertexArray> m_SquareVA;

	VitDragonEngine::OrthographicCamera m_Camera;
	glm::vec3 m_CameraPosition;
	
	float m_CameraRotation = 0.0f;
	float m_CameraRotationSpeed = 2.0f;
	
	float m_CameraMoveSpeed = 0.1f;
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