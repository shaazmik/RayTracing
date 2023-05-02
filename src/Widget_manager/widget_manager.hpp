#ifndef WIDGET_MANAGER_HPP
#define WIDGET_MANAGER_HPP

#include "../Widget/widget.hpp"
#include "../log/log.hpp"



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

        void setCapacity(unsigned int capacity)
        {
            if (m_widgetArr == nullptr)
            {
                m_widgetArrCapacity = capacity;
                m_widgetArr = new Widget*[capacity];
            }
            else
            {
                LOG_MSG("[ERROR]: MEMORY")
            }
        }

        void addWidget(Widget* widget)
        {
            if (m_widgetArrCapacity > m_widgetArrCount)
            {
                m_widgetArr[m_widgetArrCount] = widget;
                m_widgetArrCount++;
            }
            else
            {
                LOG_MSG("[ERROR]: WIDGET MANAGER IS OVERFLOW");
                logPrintVar(m_widgetArr);
                assert(0);
            }
        }

        void deleteWidget()
        {
            if (m_widgetArrCount >= 0)
            {
                m_widgetArr[m_widgetArrCount] = nullptr;
            }
            else
            {
                LOG_MSG("[ERROR]: WIDGET MANAGER IS EMPTY");
                assert(0);
            }
        }

        void onClick(int x, int y) override
        {
            for (int i = 0; i < m_widgetArrCount; i++)
            {
                m_widgetArr[i]->onClick(x, y);
            }
        }

        void draw() override
        {
            for (int i = 0; i < m_widgetArrCount; i++)
            {
                m_widgetArr[i]->draw();
            }
        }

    private:
        Widget** m_widgetArr             = nullptr;
        unsigned int m_widgetArrCapacity = 0;
        unsigned int m_widgetArrCount    = 0;
};

#endif