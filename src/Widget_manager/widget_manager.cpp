#include "./widget_manager.hpp"

void WidgetManager::setCapacity(unsigned int capacity)
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

void WidgetManager::addWidget(Widget* widget)
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

void WidgetManager::deleteWidget()
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

void WidgetManager::onClick(int x, int y)
{
    for (int i = 0; i < m_widgetArrCount; i++)
    {
        m_widgetArr[i]->onClick(x, y);
    }
}

void WidgetManager::draw()
{
    for (int i = 0; i < m_widgetArrCount; i++)
    {
        m_widgetArr[i]->draw();
    }
}