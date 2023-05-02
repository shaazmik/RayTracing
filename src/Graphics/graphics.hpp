#ifndef WIN_HPP
#define WIN_HPP

#include <SFML/Graphics.hpp>
#include "../constants.hpp"
#include "../log/log.hpp"
#include "./pscolor.hpp"

namespace PGL
{
    class Graphics
    {
    private:
        Graphics(): m_width(WinWidth), m_height(WinHeight)
        {
            m_window.create(sf::VideoMode(m_width, m_height), "Paramon_64");
        }

        int m_width  = WinWidth;
        int m_height = WinHeight;

        inline static Graphics* instancePtr = nullptr;

        bool m_winOpen = true;

    public:

        sf::RenderWindow m_window;

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

        void display()
        {
            m_window.display();
        }

        bool isOpen()
        {
            return m_window.isOpen();
        }

        void clear()
        {
            m_window.clear();
        }

    };
}


#endif