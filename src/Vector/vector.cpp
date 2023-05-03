#include "vector.hpp"


Vector orthogonal_2d_only(const Vector& v)
{
    return Vector {v.m_y, -v.m_x};
}

Vector operator +(const Vector &v1, const Vector &v2)
{
    Vector result(v1.m_x + v2.m_x,
                  v1.m_y + v2.m_y,
                  v1.m_z + v2.m_z);

    return result;
}

Vector operator -(const Vector &v1, const Vector &v2)
{
    Vector result(v1.m_x - v2.m_x,
                  v1.m_y - v2.m_y,
                  v1.m_z - v2.m_z);
    
    return result;
}


double operator *(const Vector &v1, const Vector &v2)
{
    return v1.m_x * v2.m_x + v1.m_y * v2.m_y + v1.m_z * v2.m_z;
}

Vector operator* (const Vector& v, const double mul)
{
    return Vector {v.m_x * mul, v.m_y * mul, v.m_z * mul};
}

Vector operator* (const double mul, const Vector& v)
{
    return Vector {v.m_x * mul, v.m_y * mul, v.m_z * mul};
}

Vector operator- (const Vector& v)
{
    return Vector{ - v.m_x, - v.m_y, - v.m_z };
}


void Vector::rotate_z(const double rad_angle)
{
    double sinus  = sin(rad_angle);
    double cosine = cos(rad_angle);

    rotate_z(sinus, cosine);
}

void Vector::rotate_z(const double sin, const double cos)
{
    double x1 = m_x;
    double y1 = m_y;

    setX(cos * x1 - sin * y1);
    setY(sin * x1 + cos * y1);
}

//---------------------------------------------------------

void Vector::rotate_x(const double rad_angle)
{
    double sinus  = sin(rad_angle);
    double cosine = cos(rad_angle);

    rotate_x(sinus, cosine);
}

void Vector::rotate_x(const double sin, const double cos)
{
    double y1 = m_y;
    double z1 = m_z;

    setY(cos * y1 - sin * z1);
    setZ(sin * y1 + cos * z1);
}

//---------------------------------------------------------


void Vector::rotate_y(const double rad_angle)
{
    double sinus  = sin(rad_angle);
    double cosine = cos(rad_angle);

    rotate_y(sinus, cosine);
}

void Vector::rotate_y(const double sin, const double cos)
{
    double x1 = m_x;
    double z1 = m_z;

    setX(cos * x1 - sin * z1);
    setZ(sin * x1 + cos * z1);
}

//---------------------------------------------------------

void Vector::normalize()
{
    double length = len();
    (*this) *= (1 / length);
}
