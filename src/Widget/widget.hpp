#ifndef WIDGET_HPP
#define WIDGET_HPP

#include "../Graphics/graphics.hpp"
#include "../constants.hpp"

class Widget
{
public:
    Widget(PGL::Graphics* mainWin, int width, int height): m_mainWin(mainWin), m_width(width), m_height(height)
    {
        m_mainWin->setSize(m_rectangle, m_width, m_height);
    }

    Widget(PGL::Graphics* mainWin): m_mainWin(mainWin)
    {
        m_mainWin->setSize(m_rectangle, WinWidth, WinHeight);
    }

    ~Widget()
    {
        m_mainWin = nullptr;
    }

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
    int m_width  = WinWidth;
    int m_height = WinHeight;
    int m_posX   = 0;
    int m_posY   = 0;

    sf::RectangleShape m_rectangle;

protected:
    class PGL::Graphics* m_mainWin = nullptr;

};


class WidgetManager : public Widget
{
public:
    WidgetManager(PGL::Graphics* mainWin, int size):
    Widget(mainWin)
    {
        m_size = size;
        m_widgetArr = new Widget*[size];
        m_count = 0;
    }

   ~WidgetManager()
   {
        delete[] m_widgetArr;
   }

    virtual void controller(sf::Event event) {$$}

    void draw();

    void add(Widget* curWidget);

private:
    int m_size = 0;


protected:
    Widget** m_widgetArr = nullptr;
    int m_count = 0;

};

#endif