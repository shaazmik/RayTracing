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


int Widget::getPosX()
{
    return m_posX;
}

int Widget::getPosY()
{
    return m_posY;
}


void Widget::setSize(unsigned int width, unsigned int height)
{
    m_width  = width;
    m_height = height;
    PGL::Graphics::getInstance()->setSize(m_rectangle, width, height);
}