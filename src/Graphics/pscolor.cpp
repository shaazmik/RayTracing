#include "./pscolor.hpp"


void PGL::PsColor::rgb_norm()
{
    double r = m_currentClr.r;
    double g = m_currentClr.g;
    double b = m_currentClr.b;

    if (r > 255) r = 255;
    if (r < 0)   r = 0;

    if (g > 255) g = 255;
    if (g < 0)   g = 0;

    if (b > 255) b = 255;
    if (b < 0)   b = 0;


    m_currentClr.r = r;
    m_currentClr.g = g;
    m_currentClr.b = b;
}


PGL::PsColor PGL::operator+(const PGL::PsColor& c1, const PGL::PsColor& c2)
{
    unsigned int r = c1.m_currentClr.r + c2.m_currentClr.r;
    unsigned int g = c1.m_currentClr.g + c2.m_currentClr.g;
    unsigned int b = c1.m_currentClr.b + c2.m_currentClr.b;
    unsigned int a = c1.m_currentClr.a + c2.m_currentClr.a;

    return PGL::PsColor(r,g,b,a);
}

PGL::PsColor PGL::operator- (const PGL::PsColor& c1, const PGL::PsColor& c2)
{
    unsigned int r = c1.m_currentClr.r - c2.m_currentClr.r;
    unsigned int g = c1.m_currentClr.g - c2.m_currentClr.g;
    unsigned int b = c1.m_currentClr.b - c2.m_currentClr.b;
    unsigned int a = c1.m_currentClr.a - c2.m_currentClr.a;


    return PGL::PsColor(r,g,b,a);
}

PGL::PsColor PGL::operator% (const PGL::PsColor& a, const PGL::PsColor& b)
{
    PGL::PsColor c = a;
    c %= b;

    return c;
}

PGL::PsColor PGL::operator* (const PGL::PsColor& c, const double m)
{
    unsigned int r = c.m_currentClr.r * m;    
    unsigned int g = c.m_currentClr.g * m;
    unsigned int b = c.m_currentClr.b * m;

    return PGL::PsColor(r, g, b, 255);
}

PGL::PsColor PGL::operator* (const double m, const PGL::PsColor& c)
{
    unsigned int r = c.m_currentClr.r * m;    
    unsigned int g = c.m_currentClr.g * m;
    unsigned int b = c.m_currentClr.b * m;


    return PGL::PsColor(r, g, b, 255);
}

PGL::PsColor PGL::col_average(const PGL::PsColor& a, const PGL::PsColor& b)
{
    PGL::PsColor sum = a + b;

    sum *= 0.1;

    return PGL::PsColor((unsigned) sum.m_currentClr.r, (unsigned) sum.m_currentClr.g, (unsigned) sum.m_currentClr.b, 255);
}


inline void PGL::PsColor::set_r(const int r)
{
    unsigned r_ = r;

    if (r > 255)
        r_ = 255;
    else if (r < 0)
        r_ = 0;

    m_currentClr.r = r;
}

//---------------------------------------------------------

inline void PGL::PsColor::set_g(const int g)
{
    unsigned g_ = g;

    if (g > 255)
        g_ = 255;
    else if (g < 0)
        g_ = 0;

    m_currentClr.g = g;
}

//---------------------------------------------------------

inline void PGL::PsColor::set_b(const int b)
{
    unsigned b_ = b;

    if (b > 255)
        b_ = 255;
    else if (b < 0)
        b_ = 0;

    m_currentClr.b = b;
}

//---------------------------------------------------------
