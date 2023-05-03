#ifndef PS_EVENT_HPP
#define PS_EVENT_HPP

#include <SFML/Graphics.hpp>


namespace PGL
{
    enum class Mouse
    {
        Nothing         = 1337,
        Right           = sf::Mouse::Button::Right,
        Left            = sf::Mouse::Button::Left,
    };

    enum class Keyboard
    {
        Nothing = 1337,
        Escape  = sf::Keyboard::Escape,
        LAlt    = sf::Keyboard::LAlt,
        RAlt    = sf::Keyboard::RAlt,
    };

    class PsEvent
    {
    public:
        PsEvent()  = default;
        ~PsEvent() = default;

        enum EventType
        {   
            Nothing            = 1337,
            Closed             = sf::Event::Closed,
            KeyPressed         = sf::Event::KeyPressed,
            MouseButtonPressed = sf::Event::MouseButtonPressed,
        };        

        EventType getEventType()
        {
            switch (m_event.type)
            {
                case sf::Event::Closed:
                    return EventType::Closed;
                    break;
                
                case sf::Event::KeyPressed:
                    return EventType::KeyPressed;
                    break;

                case sf::Event::MouseButtonPressed:
                    return EventType::MouseButtonPressed;
                    break;
                default:
                    break;
            }

            return EventType::Nothing;
        }

        Mouse getMouseButton()
        {
            switch(m_event.mouseButton.button)
            {
                case sf::Mouse::Right:
                    return Mouse::Right;
                    break;
                
                case sf::Mouse::Left:
                    return Mouse::Left;
                    break;
                
                default:
                    break;
            }

            return Mouse::Nothing;
        }

        inline int getMouseClickX(){return m_event.mouseButton.x;}
        inline int getMouseClickY(){return m_event.mouseButton.y;}
        
        friend class Graphics;

    private:
        sf::Event m_event;
    };



}

#endif