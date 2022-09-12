#include "vdepch.h"
#include "Application.h"

#include "VitDragonEngine/Log.h"

#include <GLFW/glfw3.h>

namespace VitDragonEngine{

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	VitDragonEngine::Application::Application(){
		m_Window = std::unique_ptr<Window>( Window::Create() );
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	}

	VitDragonEngine::Application::~Application(){
	}


	void Application::OnEvent( Event &e ){
		EventDispatcher dispatcher( e );

		dispatcher.Dispatch<WindowCloseEvent>( BIND_EVENT_FN( OnWindowClose ) );

		VDE_CORE_TRACE("{0}", e);

		for( auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ){
			( *--it )->OnEvent( e );
			if( e.Handled )
				break;
		}
	}

	void Application::PushLayer( Layer *layer ){
		m_LayerStack.PushLayer( layer );
	}

	void Application::PushOverlay( Layer *layer ){
		m_LayerStack.PushOverlay( layer );
	}

	void Application::Run(){

		while( m_Running ){
			glClearColor( 1, 0, 1, 1 );
			glClear( GL_COLOR_BUFFER_BIT );
			for( Layer *layer : m_LayerStack )
				layer->OnUpdate();
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose( WindowCloseEvent &e ){
		m_Running = false;
		return true;
	}
}
