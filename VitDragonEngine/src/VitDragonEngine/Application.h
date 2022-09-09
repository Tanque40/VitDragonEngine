#pragma once

#include "Core.h"
#include "Events/Event.h"

namespace VitDragonEngine{

	class VITDRAGONENGINE_API Application{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be define in the client side
	Application *CreateApplication();
}