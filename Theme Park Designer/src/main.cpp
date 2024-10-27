#include "pch.h"

#include "Application.h"

int main()
{
    TPD::Application* app = new TPD::Application("Theme Park Designer");
    app->Run();
    delete app;

    return 0; 
}