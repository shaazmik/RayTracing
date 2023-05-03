#ifndef COLOR_BUTTON_HPP
#define COLOR_BUTTON_HPP

#include "../Graphics/graphics.hpp"
#include "../Graphics/pscolor.hpp"
#include "../Sphere/sphere.hpp"
#include "../Abstract_button/abstract_button.hpp"

class SphereColorButton : public AbstractButton
{
public:
    SphereColorButton() : AbstractButton()
    {}

    ~SphereColorButton() = default;

    void initObject(Sphere* sphere, PGL::PsColor color)
    {
        setColor(color);
        m_sphere = sphere;
        m_color  = color;
    }

    void action() override
    {
        if (m_sphere != nullptr)
        {
            m_sphere->setColor(m_color);
        }
        else
        {
            logPrintVar(m_sphere);
            LOG_MSG("SphereColorButton doesn't initialize")
            assert(0);
        }
    }

private:
    Sphere* m_sphere     = nullptr;
    PGL::PsColor m_color; 
    
};


#endif