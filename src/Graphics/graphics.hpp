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
    public:
        Graphics(const int width, const int height): m_width(width), m_height(height)
        {
            m_window.create(sf::VideoMode(width, height), "Paramon_64");
        }

        Graphics() = default;

        ~Graphics()
        {
            m_window.clear();
            m_winOpen = false;
        }

        void setSize(sf::RectangleShape& widget, const int width, const int height);

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

        sf::RenderWindow m_window;

    private:
        int m_width  = WinWidth;
        int m_height = WinHeight;

        bool m_winOpen = true;
    };
}


#endif