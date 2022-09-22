#pragma once

#include "Core.h"

#include "Window.h"
#include "VitDragonEngine/LayerStack.h"
#include "VitdragonEngine/Events/Event.h"
#include "VitDragonEngine/Events/ApplicationEvent.h"

#include "VitDragonEngine/ImGui/ImGuiLayer.h"

#include "VitDragonEngine/Renderer/Shader.h"

namespace VitDragonEngine{

	class VITDRAGONENGINE_API Application{
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

		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;

		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application *s_Instance;
	};

	// To be define in the client side
	Application *CreateApplication();
}