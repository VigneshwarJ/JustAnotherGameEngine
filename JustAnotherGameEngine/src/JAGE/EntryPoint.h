#pragma once
#include "JAGE/Core/Application.h"



#ifdef JAGE_PLATFORM_WINDOWS
extern JAGE::Application* JAGE::CreateApp();
int main()
{
	auto app = JAGE::CreateApp();
	app->run();
	delete app;
}

#endif // GE_PLATFORM_WINDOWS