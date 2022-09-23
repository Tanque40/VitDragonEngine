#pragma once

#include "VitDragonEngine/Renderer/Buffer.h"

namespace VitDragonEngine{

	class OpenGLVertexBuffer : public VertexBuffer{
	public:
		OpenGLVertexBuffer( float *vertices, uint32_t size );
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void UnBind() const;

		virtual const BufferLayout &GetLayout() const override{ return m_Layout; }
		virtual void SetLayout( const BufferLayout &layout ) override{ m_Layout = layout; }

	private:
		uint32_t m_RendererID;
		BufferLayout m_Layout;
	};

	class OpenGLIndexBuffer : public IndexBuffer{
	public:
		OpenGLIndexBuffer( uint32_t *vertices, uint32_t size );
		virtual ~OpenGLIndexBuffer();
		
		virtual void Bind() const override;
		virtual void UnBind() const override;

		virtual uint32_t GetCount() const{ return m_Count; };

	private:
		uint32_t m_RendererID, m_Count;
	};

}