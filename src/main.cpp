#include "general.hpp"
#include <unistd.h>

int main()
{
    Factory::getInstance()->setWidgetCapacity(10);
    WidgetManager* widgetman = Factory::getInstance()->makeWidgetManager();
    Widget* widget1          = Factory::getInstance()->makeWidget();
    AbstractButton* btn      = Factory::getInstance()->makeAbstractButton();
    RayTracingScene* scene   = Factory::getInstance()->makeRayTracingScene();

    PGL::PsColor color(220, 100, 50, 255);
    PGL::PsColor color2(100, 50, 10, 255);

    widget1->move(0,500);
    widget1->setSize(500, 200);
    widget1->setColor(color);

    scene->setSize(1000, 500);
    scene->move(10, 10);

    btn->setSize(20,50);
    btn->move(1000, 250);
    btn->setColor(color2);

    widgetman->setCapacity(20);
    widgetman->addWidget(scene);
    widgetman->addWidget(btn);
    widgetman->addWidget(widget1);

    widgetman->draw();
    PGL::Graphics::getInstance()->display();
    delete Factory::getInstance();

    sleep(3);
    return 0;
}
