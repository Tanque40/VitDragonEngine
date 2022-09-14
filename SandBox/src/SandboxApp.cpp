#include <VitDragonEngine.h>

class ExampleLayer : public VitDragonEngine::Layer{
public:
	ExampleLayer()
		: Layer( "Example" ){ }

	void OnUpdate() override{
		//VDE_INFO( "ExampleLayer::Update" );

		if( VitDragonEngine::Input::IsKeyPressed( VDE_KEY_TAB ) ){
			VDE_INFO( "Tab key is pressed!" );
		}
	}

	void OnEvent( VitDragonEngine::Event &event ) override{
		
		if( event.GetEventType() == VitDragonEngine::EventType::KeyPressed ){
			VitDragonEngine::KeyPressedEvent &e = ( VitDragonEngine::KeyPressedEvent & ) event;

			VDE_TRACE( "{0}", ( char ) e.GetKeyCode() );
		}
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