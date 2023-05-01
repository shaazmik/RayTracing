#include "widget.hpp"
void Widget::draw()
{
    PGL::Graphics::getInstance()->m_window.draw(m_rectangle);

}

void Widget::setColor(PGL::PsColor& color)
{
    PGL::Graphics::getInstance()->setFillColor(m_rectangle, color);
}

void Widget::move(int xOffset, int yOffset)
{
    m_posX += xOffset;
    m_posY += yOffset;
    PGL::Graphics::getInstance()->move(m_rectangle, xOffset, yOffset);
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
// ещё один менеджер для палитры 