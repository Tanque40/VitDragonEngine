#include <VitDragonEngine.h>

class SandBox : public VitDragonEngine::Application{
public:
	SandBox(){

	}

	~SandBox(){

	}

};

VitDragonEngine::Application *VitDragonEngine::CreateApplication(){
	return new SandBox();
}