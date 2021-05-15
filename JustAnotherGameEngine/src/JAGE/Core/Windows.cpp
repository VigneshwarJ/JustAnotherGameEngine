#include "Windows.h"
#include "Base.h"
#include "JAGE/Platform/Window/GLFWWindow.h"
using namespace JAGE;
Scope<Window> JAGE::Window::Create(const WindowsData& props)
{
#ifdef JAGE_PLATFORM_WINDOWS
	return CreateScope<GLFWWindow>(props);
#else
	return nullptr;
#endif
}
