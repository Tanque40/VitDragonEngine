#include "vdepch.h"
#include "Shader.h"

#include "Renderer.h"

#include "Platform/OpenGL/OpenGLShader.h"

namespace VitDragonEngine{

	Shader* Shader::Create( const std::string& vertexSrc, std::string& fragmentSrc ){

		switch( Renderer::GetAPI() ){
			case RendererAPI::API::None:
				VDE_CORE_ASSERT( false, "RendererAPI::None is currently not supported!" );
				return nullptr;

			case RendererAPI::API::OpenGL:
				return new OpenGLShader(vertexSrc, fragmentSrc);
		}

		VDE_CORE_ASSERT( false, "Unknown RendererAPI!" );
		return nullptr;

	}

}