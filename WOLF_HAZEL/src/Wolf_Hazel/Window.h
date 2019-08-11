#pragma once

#include "whpch.h"

#include "Wolf_Hazel/Core.h"
#include "Wolf_Hazel/Event/Event.h"

namespace Wolf_Hazel {

	struct WindowProps
	{
		std::string Title;
		UINT32 Width;
		UINT32 Height;

		WindowProps(const std::string& title = "Wolf_Hazel Engine",
			UINT32 width = 1280,
			UINT32 height = 720) : Title(title), Width(width), Height(height)
		{};
	};

	class WH_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Window* Create(const WindowProps& props = WindowProps());
	};
}