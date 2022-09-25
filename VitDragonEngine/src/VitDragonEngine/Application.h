#pragma once

#include "Core.h"

#include "Window.h"
#include "VitDragonEngine/LayerStack.h"
#include "VitdragonEngine/Events/Event.h"
#include "VitDragonEngine/Events/ApplicationEvent.h"

#include "VitDragonEngine/ImGui/ImGuiLayer.h"

#include "VitDragonEngine/Renderer/Shader.h"
#include "VitDragonEngine/Renderer/Buffer.h"
#include "VitDragonEngine/Renderer/VertexArray.h"

#include "VitDragonEngine/Renderer/OrthographicCamera.h"

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

		std::shared_ptr<Shader> m_Shader;
		std::shared_ptr<VertexArray> m_VertexArray;

		std::shared_ptr<Shader> m_BlueShader;
		std::shared_ptr<VertexArray> m_SquareVA;

		OrthographicCamera m_Camera;
	private:
		static Application *s_Instance;
	};

	// To be define in the client side
	Application *CreateApplication();
}