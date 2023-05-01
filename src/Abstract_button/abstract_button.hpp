#ifndef ABSTRACT_BTN_PS
#define ABSTRACT_BTN_PS

#include "../Widget/widget.hpp"

class AbstractBtn : public Widget
{
public:
    AbstractBtn(PGL::Graphics* mainWin):
        Widget(mainWin)
        {}

    AbstractBtn(PGL::Graphics* mainWin, int width, int height):
        Widget(mainWin, width, height)
        {}

    ~AbstractBtn() = default;

    bool getPressStatus()
    { return m_press; }

    bool switchPressStatus()
    {
        m_press = !(m_press);
        return m_press;
    }

    bool getClickedStatus()
    { return m_clicked; }

    bool switchClickedStatus()
    {
        m_clicked = !(m_clicked);
        return m_clicked;
    }

    virtual void action()
    {
        if (m_clicked)
        {
            PGL::PsColor clr(255, 0, 0, 100);
            setColor(clr);
        }
        else
        {
            PGL::PsColor clr(150, 150, 150, 200);
            setColor(clr);
        }

        if (m_press)
        {
            PGL::PsColor clr(0, 0, 255, 250);
            setColor(clr);
        }
        else
        {
            PGL::PsColor clr(0,150, 0, 255);
            setColor(clr);
        }
    }

protected:

    bool m_clicked = false;
    bool m_press   = false;
};


class AbstractBtnManager : public WidgetManager
{
public:
    AbstractBtnManager(PGL::Graphics* mainWin, int size):
        WidgetManager(mainWin, size)
        {
            m_abstractBtnArr = (AbstractBtn**)m_widgetArr;
        }

    ~AbstractBtnManager() = default;

    void controller(sf::Event event);

private:

protected:

    int m_idCurrentBtn = -1;

    AbstractBtn** m_abstractBtnArr = nullptr;
};


#endif
