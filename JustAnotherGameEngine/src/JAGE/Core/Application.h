#pragma once
#include "JAGE/Core/Base.h"
#include "JAGE/Core/Windows.h"


// precompiled header

namespace JAGE
{
	class JAGE_API Application
	{
	public:
		Application();
		~Application();
		void run();
		void onEvent(Event& event);
	private:
		Scope<Window> mWindow;
		bool mRunning;
	};
	//To be defined in client
	Application* CreateApp();

}

