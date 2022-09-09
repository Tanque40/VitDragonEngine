#pragma once

#ifdef VDE_PLATFORM_WINDOWS

extern VitDragonEngine::Application *VitDragonEngine::CreateApplication();

	void main(int argc, char** argv){

		VitDragonEngine::Log::Init();
		VDE_CORE_WARN("Initialiazed Log!");
		int a = 5;
		VDE_INFO("Hi! var={0}", a);

		auto app = VitDragonEngine::CreateApplication();
		app->Run();
		delete app;
	}

#endif