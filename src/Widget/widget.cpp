#include "widget.hpp"

void Widget::draw()
{
    m_mainWin->m_window.draw(m_rectangle);
}

void Widget::setColor(PGL::PsColor& color)
{
    m_mainWin->setFillColor(m_rectangle, color);
}

void Widget::move(int xOffset, int yOffset)
{
    m_posX += xOffset;
    m_posY += yOffset;
    m_mainWin->move(m_rectangle, xOffset, yOffset);
}


double Widget::getPosX()
{
    return m_posX;
}

double Widget::getPosY()
{
    return m_posY;
}

bool   Widget::checkPointInWidget(int x, int y)
{
    return ((m_posX - m_width < x) && (x < m_posX + m_width) && (m_posY - m_height < y) && (y < m_posY + m_height));
}

void WidgetManager::draw()
{
    for (int i = 0; i < m_count; i++)
    {
        m_widgetArr[i]->draw();
    }
}

void WidgetManager::add(Widget* curWidget)
{
    if (m_count + 1 > m_size)
    {   
        LOG_OBJECT(m_count, curWidget);
        LOG_CUR_VAR(m_count);
        return;
    }

    m_widgetArr[m_count] = curWidget;
    m_count++;
}


// Нам надо делать тулы(инструменты)
// Множество классов с разным поведением, которые мы объединяем с помощью базового класса,
// основная идея ООП в С++, ДИНАМИЧЕСКИЙ ПОЛИМОРФИЗМ
// мы не знаем с каким точно классом мы работаем
// если задачу можно разложить на базу и отличия в виртуальных функциях и классах
// мы это разбирали на виджетах , менеджер виджетов, контейнерный виджет, создали иерархию виджетов
// посмотреть на ту же знадачу, с помощью других паттернов
// нужно сделать интсрументы для фотошопа!!!
// тулы изменяют некоторый объект
// плюс ГУИ для инструментов
// есть контейнерный класс, который объединяет кнопки, есть контролер, так, что активирует состояния кнопок
// эта палитра делегирует обращения к активному инструменту
// инструментальная кнопка содержит х у и Canvas*
// действие + стейт = класс с функцией (инструмента)
// абстрактный класс инструментов
// и менеджер 
// ещё один менеджер для палитры свойств