#pragma once
#include <string>
#include <functional>
#include <JAGE/Events/Event.h>

namespace JAGE
{
	struct WindowsData
	{
		std::string Title;
		uint32_t Width;
		uint32_t Height;

		WindowsData(const std::string& title = "J.A.G.E",
			uint32_t width = 1920,
			uint32_t height = 1080)
			: Title(title), Width(width), Height(height)
		{
		}
	};
	class Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void OnUpdate() = 0;

		virtual uint32_t GetWidth() const = 0;
		virtual uint32_t GetHeight() const = 0;

		// Window attributes
		virtual void SetEventCallback(const EventCallbackFn & callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void closeWindow() const = 0;

		virtual void* GetNativeWindow() const = 0;

		static Scope<Window> Create(const WindowsData& props = WindowsData());
	};
}
