#ifndef COLOR_BUTTON_HPP
#define COLOR_BUTTON_HPP

#include "../Graphics/graphics.hpp"
#include "../Graphics/pscolor.hpp"
#include "../Raytracing/Scene_objects/scene_objects.hpp"
#include "../Abstract_button/abstract_button.hpp"
#include "../Raytracing/colour.hpp"

class SphereColorButton : public AbstractButton
{
public:
    SphereColorButton() : AbstractButton()
    {}

    ~SphereColorButton() = default;

    void initObject(Non_trans_sphere* sphere, Colour& color)
    {
        PGL::PsColor btnClr= PGL::PsColor(200, 150, 50, 255);
        m_sphere = sphere;
        m_color  = color;
    }

    void action() override
    {
        if (m_sphere != nullptr)
        {
            LOG_MSG("ACTION")
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
    Non_trans_sphere* m_sphere     = nullptr;
    Colour m_color; 
    
};


#endif