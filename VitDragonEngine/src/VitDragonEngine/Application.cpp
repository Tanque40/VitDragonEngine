#include "vdepch.h"
#include "Application.h"

#include "VitDragonEngine/Events/ApplicationEvent.h"
#include "VitDragonEngine/Log.h"

namespace VitDragonEngine{

	VitDragonEngine::Application::Application(){
	}

	VitDragonEngine::Application::~Application(){
	}

	void Application::Run(){

		WindowResizeEvent e( 1280, 720 );
		if( e.IsInCategory( EventCategoryApplication ) ){ 
			VDE_TRACE( e );
		}
		if( e.IsInCategory( EventCategoryInput ) ){
			VDE_TRACE( e );
		}
		while( true );
	}

}
