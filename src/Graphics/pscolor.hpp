#ifndef PS_COLOR_HPP
#define PS_COLOR_HPP

#include <SFML/Graphics.hpp>
#include "../log/log.hpp"
namespace PGL
{

    class PsColor
    {
    public:
        PsColor(unsigned int R, unsigned int G, unsigned int B, unsigned int Alpha)
        {
            m_currentClr.r = R;
            m_currentClr.g = G;
            m_currentClr.b = B;
            m_currentClr.a = Alpha;

            rgb_norm();
        }

        PsColor()
        {
            m_currentClr.r = 0;
            m_currentClr.g = 0;
            m_currentClr.b = 0;
            m_currentClr.a = 0; 

            rgb_norm();  
        }

        PsColor(const PsColor& color)
        {
            m_currentClr.r = color.m_currentClr.r;
            m_currentClr.g = color.m_currentClr.g;
            m_currentClr.b = color.m_currentClr.b;
            m_currentClr.a = color.m_currentClr.a;

            rgb_norm();
        }

        ~PsColor()
        {
            m_currentClr = sf::Color::White;
        }

        friend PGL::PsColor operator+  (const PGL::PsColor& a, const PGL::PsColor& b);
        friend PGL::PsColor operator-  (const PGL::PsColor& a, const PGL::PsColor& b);
        friend PGL::PsColor operator%  (const PGL::PsColor& a, const PGL::PsColor& b);
        friend PGL::PsColor operator*  (const PGL::PsColor& c, const double  m);
        friend PGL::PsColor operator*  (const double  m, const PGL::PsColor& c);
        friend PGL::PsColor col_average(const PGL::PsColor& a, const PGL::PsColor& b);


        PsColor& operator+= (const PGL::PsColor& c)
        {
            m_currentClr.r += c.m_currentClr.r;
            m_currentClr.g += c.m_currentClr.g;
            m_currentClr.b += c.m_currentClr.b;

            rgb_norm();
            return *this;
        }

        PsColor& operator%= (const PGL::PsColor& c)
        {
            double r1 = m_currentClr.r;
            double g1 = m_currentClr.g;
            double b1 = m_currentClr.b;

            double r2 = c.m_currentClr.r;
            double g2 = c.m_currentClr.g;
            double b2 = c.m_currentClr.b;

            
            r1 = r1 * (1 / 255.0);
            g1 = g1 * (1/ 255.0);
            b1 = b1 * (1/ 255.0); 

            r2 = r2 * (1 / 255.0);
            g2 = g2 * (1 / 255.0);
            b2 = b2 * (1 / 255.0); 


            double r = 255 * (r1 * r2);
            double g = 255 * (g1 * g2);
            double b = 255 * (b1 * b2);

            m_currentClr.r = r;
            m_currentClr.g = g;            
            m_currentClr.b = b;
            rgb_norm();
                
            return *this;
        }

        PsColor& operator*= (const double mul)
        {
            m_currentClr.r *= mul;
            m_currentClr.g *= mul;
            m_currentClr.b *= mul;

            rgb_norm();
            return *this;
        }

        void SetRGB(unsigned char R, unsigned char G, unsigned char B, unsigned char Alpha)
        {
            m_currentClr.r = R;
            m_currentClr.g = G;
            m_currentClr.b = B;
            m_currentClr.a = Alpha;

            rgb_norm();
        }

        inline void set_r(const int r);
        inline void set_g(const int g);
        inline void set_b(const int b);

        inline unsigned char get_r() const {return (unsigned char)m_currentClr.r;}
        inline unsigned char get_g() const {return (unsigned char)m_currentClr.g;}
        inline unsigned char get_b() const {return (unsigned char)m_currentClr.b;}
        inline unsigned char get_a() const {return (unsigned char)m_currentClr.a;}

        friend class Graphics;
        friend class Widget;
    private:
        sf::Color m_currentClr = sf::Color::Magenta;

        void rgb_norm();
    };

}



// static const PGL::PsColor Colour_red    (255,   0,   0, 255);
// static const PGL::PsColor Colour_green  (  0, 255,   0, 255);
// static const PGL::PsColor Colour_blue   (  0,   0, 255, 255);

// static const PGL::PsColor Colour_white  (255, 255, 255, 255);
// static const PGL::PsColor Colour_black  (  0,   0,   0, 255);

// static const PGL::PsColor Colour_yellow (255, 255,   0, 255);
// static const PGL::PsColor Colour_cyan   (  0, 255, 255, 255);
// static const PGL::PsColor Colour_magenta(255,   0, 255, 255);
#endif