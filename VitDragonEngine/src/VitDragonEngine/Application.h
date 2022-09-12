#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "VitDragonEngine/Events/ApplicationEvent.h"

#include "Window.h"

namespace VitDragonEngine{

	class VITDRAGONENGINE_API Application{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent( Event &e );

	private:
		bool OnWindowClose( WindowCloseEvent &e );

		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
	};

	// To be define in the client side
	Application *CreateApplication();
}