#include "GLFWWindow.h"
#include <iostream>
#include <JAGE/Events/ApplicationEvent.h>
#include <JAGE/Events/KeyEvent.h>
#include <JAGE/Events/MouseEvent.h>
using namespace JAGE;

GLFWWindow::GLFWWindow(const WindowsData& data)
{
	mTitle = data.Title;
	mWindowData.mWidth = data.Width;
	mWindowData.mHeight = data.Height;
	std::cout << "Hello";
	init();

}

GLFWWindow::~GLFWWindow()
{
	glfwTerminate();
	std::cout << "Deleting here " << "GLFWWindow";
}

void JAGE::GLFWWindow::init()
{
	// Vulkan is available, at least for compute
	glfwInit();
	std::cout << "Hello";

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
	mWindow = glfwCreateWindow(mWindowData.mWidth, mWindowData.mHeight, mTitle.c_str(), NULL, NULL);

	glfwSetWindowUserPointer(mWindow,&mWindowData);
	SetVSync(true);

	// Set GLFW callbacks
	glfwSetWindowSizeCallback(mWindow, [](GLFWwindow* window, int width, int height)
	{
		auto& data = *(Data*)glfwGetWindowUserPointer(window);
		data.mWidth = width;
		data.mHeight = height;

		WindowResizeEvent event(width, height);
		data.mEventCallback(event);
	});

	glfwSetWindowCloseCallback(mWindow, [](GLFWwindow* window)
	{
		Data& data = *(Data*)glfwGetWindowUserPointer(window);
		WindowCloseEvent event;
		data.mEventCallback(event);
	});

	glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		Data& data = *(Data*)glfwGetWindowUserPointer(window);

		switch (action)
		{
		case GLFW_PRESS:
		{
			KeyPressedEvent event(key, 0);
			data.mEventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			KeyReleasedEvent event(key);
			data.mEventCallback(event);
			break;
		}
		case GLFW_REPEAT:
		{
			KeyPressedEvent event(key, 1);
			data.mEventCallback(event);
			break;
		}
		}
	});

	glfwSetCharCallback(mWindow, [](GLFWwindow* window, unsigned int keycode)
	{
		Data& data = *(Data*)glfwGetWindowUserPointer(window);

		KeyTypedEvent event(keycode);
		data.mEventCallback(event);
	});

	glfwSetMouseButtonCallback(mWindow, [](GLFWwindow* window, int button, int action, int mods)
	{
		Data& data = *(Data*)glfwGetWindowUserPointer(window);

		switch (action)
		{
		case GLFW_PRESS:
		{
			MouseButtonPressedEvent event(button);
			data.mEventCallback(event);
			break;
		}
		case GLFW_RELEASE:
		{
			MouseButtonReleasedEvent event(button);
			data.mEventCallback(event);
			break;
		}
		}
	});

	glfwSetScrollCallback(mWindow, [](GLFWwindow* window, double xOffset, double yOffset)
	{
		Data& data = *(Data*)glfwGetWindowUserPointer(window);

		MouseScrolledEvent event((float)xOffset, (float)yOffset);
		data.mEventCallback(event);
	});

	glfwSetCursorPosCallback(mWindow, [](GLFWwindow* window, double xPos, double yPos)
	{
		Data& data = *(Data*)glfwGetWindowUserPointer(window);

		MouseMovedEvent event((float)xPos, (float)yPos);
		data.mEventCallback(event);
	});



}

void JAGE::GLFWWindow::OnUpdate()
{
	glfwPollEvents();
}

uint32_t JAGE::GLFWWindow::GetWidth() const
{
	return mWindowData.mWidth;
}

uint32_t JAGE::GLFWWindow::GetHeight() const
{
	return mWindowData.mHeight;
}

void JAGE::GLFWWindow::SetEventCallback(const EventCallbackFn& callback)
{
	mWindowData.mEventCallback = callback;
}

void JAGE::GLFWWindow::SetVSync(bool enabled)
{
}

bool JAGE::GLFWWindow::IsVSync() const
{
	return false;
}

void JAGE::GLFWWindow::closeWindow() const
{
	glfwDestroyWindow(mWindow);
}

void* JAGE::GLFWWindow::GetNativeWindow() const
{
	return nullptr;
}
