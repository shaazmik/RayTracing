#include "general.hpp"
#include <unistd.h>

int main()
{
    Factory::getInstance()->setWidgetCapacity(10);
    WidgetManager*   desktop = Factory::getInstance()->makeWidgetManager();
    AbstractButton*  btn     = Factory::getInstance()->makeAbstractButton();
    RayTracingScene* scene   = Factory::getInstance()->makeRayTracingScene();

    PGL::PsColor color(220, 100, 50, 255);
    PGL::PsColor color2(0, 250,  10, 255);

    scene->setSize(1920, 1080);
    scene->setColor(color);


    btn->setSize(40,25);
    btn->move(1850, 1040);
    btn->setColor(color2);

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
