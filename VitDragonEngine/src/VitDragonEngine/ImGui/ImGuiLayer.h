#pragma once

#include "VitDragonEngine/Layer.h"

#include "VitDragonEngine/Events/ApplicationEvent.h"
#include "VitDragonEngine/Events/KeyEvent.h"
#include "VitDragonEngine/Events/MouseEvent.h"

namespace VitDragonEngine{

	class VITDRAGONENGINE_API ImGuiLayer : public Layer{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	
	private:
		float m_Time = 0.0f;
	};

}