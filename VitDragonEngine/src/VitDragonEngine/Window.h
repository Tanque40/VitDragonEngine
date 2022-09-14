#pragma once

#include "vdepch.h"

#include "VitDragonEngine/Core.h"
#include "VitDragonEngine/Events/Event.h"

namespace VitDragonEngine{

	struct WindowProps{
		std::string Title;
		unsigned int Width;
		unsigned int Height;

		WindowProps(const std::string& title = "VitDragon Engine",
					unsigned int width = 1280,
					unsigned int height = 720)
			: Title(title), Width(width), Height(height) { }
	};

	// Interface representing a desktop system based window
	// Platform independent
	// Is an interface 'cause it need to be inmplemented per platform
	class VITDRAGONENGINE_API Window{
	public:
		using EventCallbackFn = std::function<void( Event & )>;

		virtual ~Window(){}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window Attributes
		virtual void SetEventCallback( const EventCallbackFn &callback ) = 0;
		virtual void SetVSync( bool enabled ) = 0;
		virtual bool IsVSync() const = 0;

		virtual void *GetNativeWindow() const = 0;

		static Window *Create( const WindowProps &props = WindowProps() );
	};
}
