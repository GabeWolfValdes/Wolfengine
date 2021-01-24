#include "wfpch.h"
#include "Buffer.h"
#include "Shader.h"

#include "Renderer.h"
#include "OpenGL/OpenGLBuffer.h"

namespace Wolfen
{
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size)
	{
		switch( Renderer::GetAPI() )
		{

		case RendererAPI::None:
			WF_ASSERT(false, "None API is currently not supported!");
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer( vertices, size );
			break;
		}
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create( uint32_t* indices, uint32_t size )
	{
		switch( Renderer::GetAPI() )
		{

		case RendererAPI::None:
			WF_ASSERT( false, "None API is currently not supported!" );
			return nullptr;

		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer( indices, size );
			break;
		}
		return nullptr;
	}
}