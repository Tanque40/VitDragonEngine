#pragma once

#include "Core.h"

#include "Window.h"
#include "VitDragonEngine/LayerStack.h"
#include "VitdragonEngine/Events/Event.h"
#include "VitDragonEngine/Events/ApplicationEvent.h"

#include "VitDragonEngine/Core/TimeStep.h"

#include "VitDragonEngine/ImGui/ImGuiLayer.h"

namespace VitDragonEngine{

	class Application{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent( Event &e );

		void PushLayer( Layer *layer );
		void PushOverlay( Layer *layer );

		inline Window &GetWindow(){ return *m_Window; }
		
		static inline Application &Get(){ return *s_Instance; }
	private:
		bool OnWindowClose( WindowCloseEvent &e );

	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		float m_LastFrameTime = 0.0f;
	private:
		static Application *s_Instance;
	};

	// To be define in the client side
	Application *CreateApplication();
}