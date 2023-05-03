#include "general.hpp"
#include <unistd.h>

int main()
{
    Factory::getInstance()->setWidgetCapacity(10);
    Factory::getInstance()->setSphereCapacity(5);

    WidgetManager*     desktop = Factory::getInstance()->makeWidgetManager();
    SphereColorButton* btn     = Factory::getInstance()->makeSphereColorButton();
    RayTracingScene*   scene   = Factory::getInstance()->makeRayTracingScene();

    PGL::PsColor sceneColor(0, 0, 0, 255);
    PGL::PsColor btn1Color(0, 250,  10, 255);

    scene->setSize(1920, 1080);
    scene->setColor(sceneColor);


    Sphere* sphere = Factory::getInstance()->makeSphere();
    sphere->setCenter(100, 100, 50);
    sphere->setRadius(200);

    btn->setSize(40,25);
    btn->move(1850, 1040);
    btn->initObject(sphere, btn1Color);

    desktop->setCapacity(20);
    desktop->addWidget(scene);
    desktop->addWidget(btn);

    PGL::Graphics* graphLib = PGL::Graphics::getInstance();
    PGL::PsEvent   event    = PGL::PsEvent();

    while (graphLib->isOpen())
    {
        while (graphLib->pollEvent(event))
        {
            switch(event.getEventType())
            {
                case PGL::PsEvent::Closed:
                    graphLib->close();
                    break;

                case PGL::PsEvent::MouseButtonPressed:
                    desktop->controller(event);
                    break;

                default:
                    break;
            }
        }

        desktop->draw();
        graphLib->display();
        graphLib->clear();
    }

    delete Factory::getInstance();
    delete graphLib;

    return 0;
}
