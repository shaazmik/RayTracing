#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdio.h>
#include "../my_math.hpp"

class Vector
{
public:

    Vector(double x, double y, double z): m_x(x), m_y(y), m_z(z), m_sqrLen(x*x + y*y + z*z)
    {

    }

    Vector() = default;

    ~Vector()
    {
        m_x = Poison;
        m_y = Poison;
        m_z = Poison;
        m_sqrLen = Poison;
    }

    void printCoordinate()
    {
        fprintf(stdout, "x = %lf\ny = %lf\ny = %lf\n\n", m_x, m_y, m_z);
    }
    
    void mulVector(double n_times);

    void divVector(double n_times);

    void rotate(double rad);

    void synchronization();

    friend Vector operator +(const Vector &v1, const Vector &v2);

    friend Vector operator -(const Vector &v1, const Vector &v2);

    friend Vector operator *(const Vector &v1, const Vector &v2);

    Vector& operator +=(const Vector& v1)
    {
        m_x += v1.m_x;
        m_y += v1.m_y;
        m_z += v1.m_z;

        this->synchronization();

        return *this;
    }

    Vector& operator -=(const Vector& v1)
    {
        m_x -= v1.m_x;
        m_y -= v1.m_y;
        m_z -= v1.m_z;

        this->synchronization();

        return *this;
    }
   
private:
    double m_x, m_y, m_z = NAN;
    double m_sqrLen      = NAN;

    bool m_sync = true; //sync class std::optional !!!

    bool isEqualFloat(double first, double second);

    friend double dotProduct(const Vector& v1, const Vector& v2);
    friend Vector getNormal(const Vector& v1);
    friend class  Graphics;

};


#endif