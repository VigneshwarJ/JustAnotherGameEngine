#include "JAGE/Core/Windows.h"
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace JAGE
{
	class GLFWWindow : public Window
	{
	public:
		GLFWWindow(const WindowsData& data);
		~GLFWWindow() override;

		void init();
		// Inherited via Window
		virtual void OnUpdate() override;

		virtual uint32_t GetWidth() const override;

		virtual uint32_t GetHeight() const override;

		virtual void SetEventCallback(const EventCallbackFn& callback) override;

		virtual void SetVSync(bool enabled) override;

		virtual bool IsVSync() const override;

		virtual void closeWindow() const override;

		virtual void* GetNativeWindow() const override;

		
	

	private:

		std::string mTitle;
		struct Data {
			unsigned int mWidth, mHeight;
			EventCallbackFn mEventCallback;
		};
		
		GLFWwindow* mWindow;
		Data mWindowData;



	};
}


