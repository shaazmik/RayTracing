#ifndef PS_COLOR_HPP
#define PS_COLOR_HPP

#include <SFML/Graphics.hpp>

namespace PGL
{

    class PsColor
    {
    public:
        PsColor(unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha)
        {
            m_currentClr.r = R;
            m_currentClr.g = G;
            m_currentClr.b = B;
            m_currentClr.a = Alpha;    
        }

        PsColor()
        {
            m_currentClr.r = 0;
            m_currentClr.g = 0;
            m_currentClr.b = 0;
            m_currentClr.a = 0;    
        }

        PsColor(const PsColor& color)
        {
            m_currentClr.r = color.m_currentClr.r;
            m_currentClr.g = color.m_currentClr.g;
            m_currentClr.b = color.m_currentClr.b;
            m_currentClr.a = color.m_currentClr.a;
        }

        ~PsColor()
        {
            m_currentClr = sf::Color::White;
        }

        void SetRed()
        {
            m_currentClr = sf::Color::Red;
        }
        void SetBlack()
        {
            m_currentClr = sf::Color::Black;
        }
        void SetBlue()
        {
            m_currentClr = sf::Color::Blue;
        }
        void SetWhite()
        {
            m_currentClr = sf::Color::White;
        }
        void SetMagenta()
        {
            m_currentClr = sf::Color::Magenta;
        }
        void SetYellow()
        {
            m_currentClr = sf::Color::Yellow;
        }
        void SetGreen()
        {
            m_currentClr = sf::Color::Green;
        }

        void SetRGB(unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha)
        {
            m_currentClr.r = R;
            m_currentClr.g = G;
            m_currentClr.b = B;
            m_currentClr.a = Alpha;
        }

        friend class Graphics;
        friend class Widget;
    private:
        sf::Color m_currentClr = sf::Color::Magenta;

    };

}

#endif