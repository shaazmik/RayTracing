#ifndef WIDGET_MANAGER_HPP
#define WIDGET_MANAGER_HPP

#include "../Widget/widget.hpp"
#include "../log/log.hpp"
#include "../Graphics/graphics.hpp"
#include "../Graphics/psevent.hpp"


class WidgetManager : public Widget
{
    public:
        WidgetManager():Widget()
        {}

        WidgetManager(unsigned int capacity):Widget()
        {
            m_widgetArrCapacity = capacity;
            m_widgetArr = new Widget*[capacity];
        }

        ~WidgetManager()
        {
            m_widgetArrCapacity = 0;
            m_widgetArrCount    = 0;
            delete[] m_widgetArr;
        }

        virtual void controller(PGL::PsEvent event)
        {
            switch(event.getEventType())
            {
                case PGL::PsEvent::MouseButtonPressed:
                    if (event.getMouseButton() == PGL::Mouse::Left)
                    {
                        onClick(event.getMouseClickX(), event.getMouseClickY());
                    }
                    break;
                default:
                    break;
            }
        }

        void onClick(int x, int y) override;
        void draw() override;

        void setCapacity(unsigned int capacity);
        void addWidget(Widget* widget);
        void deleteWidget();


    private:
        Widget** m_widgetArr             = nullptr;
        unsigned int m_widgetArrCapacity = 0;
        unsigned int m_widgetArrCount    = 0;
};

#endif