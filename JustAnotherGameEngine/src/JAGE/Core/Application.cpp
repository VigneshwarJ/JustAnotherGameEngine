#define GLFW_INCLUDE_VULKAN
#include "JAGE/Core/Application.h"
#include "JAGE/Events/ApplicationEvent.h"

#include <iostream>
using namespace JAGE;

Application::Application()
{
    mWindow = Window::Create({"Helllo"});


    mWindow->SetEventCallback(std::bind(&Application::onEvent,
                                         this,
                                         std::placeholders::_1));

    mRunning = true;
}

Application::~Application()
{
    std::cout << "Deleting here " << "Application";
}

void Application::run()
{
    while (mRunning) 
    {
        mWindow->OnUpdate();
    }
}

void JAGE::Application::onEvent(Event& event)
{
    if (event.GetEventType() == EventType::WindowClose)
    {
        mWindow->closeWindow();
        mRunning = false;
    }
}
