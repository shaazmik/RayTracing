#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "../my_math.hpp"


class Point
{
public:
    Point(double x, double y, double z): m_x0(x), m_y0(y), m_z0(z)
    {

    }

    Point() = default;

    ~Point();

private:
    double m_x0, m_y0, m_z0 = NAN;

    int m_winX0, m_winY0, m_winZ0 = 0;
};







#endif