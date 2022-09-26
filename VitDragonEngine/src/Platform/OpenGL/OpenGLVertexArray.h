#pragma once

#include "VitDragonEngine/Renderer/VertexArray.h"

namespace VitDragonEngine{

	class OpenGLVertexArray : public VertexArray{
	public:
		OpenGLVertexArray();
		virtual ~OpenGLVertexArray();

		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual void AddVertexBuffer( const Ref<VertexBuffer> &vertexBuffer ) override;
		virtual void SetIndexBuffer( const Ref<IndexBuffer> &indexBuffer ) override;

		virtual const std::vector<Ref<VertexBuffer>> &GetVertexBuffers() const{ return m_VertexBuffers; }
		virtual const Ref<IndexBuffer> &GetIndexBuffer() const{ return m_IndexBuffers; }

	private:
		std::vector<Ref<VertexBuffer>> m_VertexBuffers;
		Ref<IndexBuffer> m_IndexBuffers;
		unsigned int m_RendererID;
	};

}