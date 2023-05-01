#ifndef COORDINATE_H
#define COORDINATE_H

#include "../SFML/Graphics.hpp"
#include "../my_math.hpp"

class CoordinateSystem
{
public:
    CoordinateSystem() = default;

    CoordinateSystem(double xMax, double yMax, double x0, double y0) : 
    m_xMax(xMax), m_yMax(yMax),
    m_x0(x0), m_y0(y0)
    {
        pixels = new sf::Uint8 [1080 * 1920 * 4];
    }

    ~CoordinateSystem()
    {
        delete[] pixels;
    }

private:
    double m_xMax, m_yMax     = NAN;
    double m_x0, m_y0         = NAN;
    double m_xScale, m_yScale = NAN;
    int    m_width, m_height  = 0;
    double m_winX0, m_winY0   = NAN;

    sf::Uint8* pixels = nullptr;

    int m_colorRed   = 40;
    int m_colorGreen = 20;
    int m_colorBlue  = 30;

    bool m_sync = true;

    friend class Graphics;
};

#endif