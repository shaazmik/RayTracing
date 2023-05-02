#ifndef ABSTRACT_BUTTON_HPP
#define ABSTRACT_BUTTON_HPP

#include "../Widget/widget.hpp"
#include "../Graphics/graphics.hpp"
#include "../Graphics/pscolor.hpp"

class AbstractButton : public Widget
{
    public:
        AbstractButton() : Widget()
        {}

        ~AbstractButton() = default;

        virtual void action(){LOG_MSG("ACTION")}
        
        void onClick(int x, int y) override
        {
            if (checkOnWidget(x, y))
            {
                action();
            }
        }

    protected:
        bool m_onClick = false;
};



#endif