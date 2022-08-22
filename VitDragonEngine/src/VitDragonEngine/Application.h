#pragma once

#include "Core.h"

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