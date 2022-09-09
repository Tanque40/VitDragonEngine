#include "vdepch.h"
#include "Application.h"

#include "VitDragonEngine/Events/ApplicationEvent.h"
#include "VitDragonEngine/Log.h"

#include <GLFW/glfw3.h>

namespace VitDragonEngine{

	VitDragonEngine::Application::Application(){
		m_Window = std::unique_ptr<Window>( Window::Create() );
	}

	VitDragonEngine::Application::~Application(){
	}

	void Application::Run(){

		while( m_Running ){
			glClearColor( 1, 0, 1, 1 );
			glClear( GL_COLOR_BUFFER_BIT );
			m_Window->OnUpdate();
		}
	}

}
