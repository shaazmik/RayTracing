#ifndef WIN_HPP
#define WIN_HPP

#include <SFML/Graphics.hpp>
#include "../constants.hpp"
#include "../log/log.hpp"
#include "./pscolor.hpp"
#include "./psevent.hpp"

namespace PGL
{
    class Graphics
    {
    private:
        Graphics(): m_width(WinWidth), m_height(WinHeight), m_window{sf::VideoMode(m_width, m_height), "", (sf::Uint32)(sf::Style::Resize | sf::Style::Close)}
        {
        }

        int m_width  = WinWidth;
        int m_height = WinHeight;

        inline static Graphics* instancePtr = nullptr;

        bool m_winOpen = true;

    public:

        sf::RenderWindow m_window{};

        ~Graphics()
        {
            m_window.clear();
            m_winOpen = false;
        }

        static Graphics* getInstance()
        {
            if (instancePtr == nullptr)
            {
                instancePtr = new Graphics();

                return instancePtr;
            }
            else
            {
                return instancePtr;
            }
        }


        void setSize(sf::RectangleShape& widget, const unsigned int width, const unsigned int height);

        void setFillColor(sf::RectangleShape& widget, PsColor& color);

        sf::Vector2f getPosition(sf::RectangleShape* widget);

        void move(sf::RectangleShape& widget, float xOffset, float yOffset);

        inline void display()
        {
            m_window.display();
        }

        inline bool isOpen()
        {
            return m_window.isOpen();
        }

        inline void clear()
        {
            m_window.clear();
        }

        inline void close()
        {
            m_window.close();
        }

        inline bool pollEvent(PGL::PsEvent& event)
        {
            return m_window.pollEvent(event.m_event);
        }

    };
}


#endif