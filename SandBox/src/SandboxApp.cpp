#include <VitDragonEngine.h>

class ExampleLayer : public VitDragonEngine::Layer{
public:
	ExampleLayer()
		: Layer( "Example" ){ }

	void OnUpdate() override{
		VDE_INFO( "ExampleLayer::Update" );
	}

	void OnEvent( VitDragonEngine::Event &event ) override{
		VDE_TRACE( "{0}", event );
	}
};

class SandBox : public VitDragonEngine::Application{
public:
	SandBox(){
		PushLayer( new ExampleLayer() );
		PushOverlay( new VitDragonEngine::ImGuiLayer() );
	}

	~SandBox(){

	}

};

VitDragonEngine::Application *VitDragonEngine::CreateApplication(){
	return new SandBox();
}