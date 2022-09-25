#include "vdepch.h"
#include "Renderer.h"

namespace VitDragonEngine{
	
	void Renderer::BeginScene(){
	
	}

	void Renderer::EndScene(){
	
	}

	void Renderer::Submit( const std::shared_ptr<VertexArray> &vertexArray ){
		vertexArray->Bind();
		RenderCommand::DrawIndexed( vertexArray );
	}

}