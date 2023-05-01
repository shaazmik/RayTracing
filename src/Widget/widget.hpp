#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "../Graphics/graphics.hpp"
#include "../constants.hpp"

class Widget
{
public:
    Widget(int width, int height): m_width(width), m_height(height)
    {
        PGL::Graphics::getInstance()->setSize(m_rectangle, m_width, m_height);
    }

    Widget()
    {
    }

    ~Widget()
    {
    }

    void setSize();
    void setColor(PGL::PsColor& color);
    void draw ();
    void close();
    double getPosX();
    double getPosY();
    int    getWidth();
    int    getHeight();
    bool   checkPointInWidget(int x, int y);
    void move(int xOffset, int yOffset);

private:
    int m_posX   = 0;
    int m_posY   = 0;
    int m_width  = 0;
    int m_height = 0;

    sf::RectangleShape m_rectangle;
};

#endif