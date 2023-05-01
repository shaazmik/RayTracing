#ifndef PS_EVENT_HPP
#define PS_EVENT_HPP

#include <SFML/Graphics.hpp>

namespace PGL
{

    class PsEvent
    {
    public:
        PsEvent()  = default;
        ~PsEvent() = default;

    private:

        sf::Event m_event;
    };
}

#endif