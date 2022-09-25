#include "vdepch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace VitDragonEngine{

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}