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
    {}

    virtual ~Widget()
    {}

    virtual bool checkOnWidget(int x, int y) {return ((m_posX < x) && (x < m_posX + m_width) && (m_posY < y) && (y < m_posY + m_height));}
    virtual void onClick(int x, int y){}
    virtual void draw ();


    void setSize(unsigned int width, unsigned int height);
    void setColor(PGL::PsColor& color);
    int getPosX();
    int getPosY();
    void move(int xOffset, int yOffset);

protected:
    int m_posX   = 0;
    int m_posY   = 0;
    int m_width  = 0;
    int m_height = 0;

    sf::RectangleShape m_rectangle;
};



#endif