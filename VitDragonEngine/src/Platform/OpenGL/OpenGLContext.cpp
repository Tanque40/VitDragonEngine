#include "vdepch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace VitDragonEngine{
	OpenGLContext::OpenGLContext( GLFWwindow *windowHandle )
		: m_WindowHandle(windowHandle) {
		VDE_CORE_ASSERT( windowHandle, "WindowHandle is null!" );
	}

	void OpenGLContext::Init(){
		glfwMakeContextCurrent( m_WindowHandle );
		int status = gladLoadGLLoader( ( GLADloadproc ) glfwGetProcAddress );
		VDE_CORE_ASSERT( status, "Failed to initialize Glad" );

		VDE_CORE_INFO( "OpenGL Info:");
		VDE_CORE_INFO( "	Vendor:	  {0}", glGetString( GL_VENDOR ) );
		VDE_CORE_INFO( "	Renderer: {0}", glGetString( GL_RENDERER ) );
		VDE_CORE_INFO( "	Version:  {0}", glGetString( GL_VERSION ) );
	}

	void OpenGLContext::SwapBuffers(){
		glfwSwapBuffers( m_WindowHandle );
	}
}