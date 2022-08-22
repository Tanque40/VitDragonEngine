#pragma once

#ifdef VDE_PLATFORM_WINDOWS

extern VitDragonEngine::Application *VitDragonEngine::CreateApplication();

	void main(int argc, char** argv){
		auto app = VitDragonEngine::CreateApplication();
		app->Run();
		delete app;
	}

#endif