#ifndef VECTOR_HPP
#define VECTOR_HPP

#include <stdio.h>
#include "../../my_math.hpp"

class Vector
{
public:

    Vector(const double x,const double y,const double z = 0): m_x(x), m_y(y), m_z(z), m_len( ((!m_x) && (!m_y) && (!m_z))? 0: NAN )
    {}

    Vector() = default;

    ~Vector()
    {
        m_x = Poison;
        m_y = Poison;
        m_z = Poison;
        m_len    = Poison;
    }

    Vector(const Vector&) = default;
    Vector(Vector&&)      = default; 

    Vector& operator = (const Vector&) = default;
    Vector& operator = (Vector&&)      = default;


    void set(const double x, const double y, const double z = 0)
    {
        m_len = ((fabs(m_x) == fabs(x)) 
             &&  (fabs(m_y) == fabs(y))
             &&  (fabs(m_z) == fabs(z)))? m_len: NAN;
        m_x = x; 
        m_y = y;
        m_z = z;
    }

    void setX(const double x)
    {
        m_len = (fabs(m_x) == fabs(x))? m_len: NAN;
        m_x = x;
    }
    void setY(const double y)
    {
        m_len = (fabs(m_y) == fabs(y))? m_len: NAN;
        m_y = y;
    }
    void setZ(const double z)
    {
        m_len = (fabs(m_z) == fabs(z))? m_len: NAN;
        m_z = z;
    }

    double x() const { return m_x; }
    double y() const { return m_y; }
    double z() const { return m_z; }

    double len() const 
    {
        if (!isnan(m_len))
            return m_len;

        m_len = sqrt(pow(m_x,2) + pow(m_y,2) + pow(m_z,2));
        return m_len;
    }

    void printCoordinate()
    {
        fprintf(stdout, "x = %lf\ny = %lf\ny = %lf\n\n", m_x, m_y, m_z);
    }

    void rotate_z(const double rad_angle);
    void rotate_z(const double sin, double cos);

    void rotate_x(const double rad_angle);
    void rotate_x(const double sin, double cos);

    void rotate_y(const double rad_angle);
    void rotate_y(const double sin, double cos);

    void normalize();

    friend Vector orthogonal_2d_only(const Vector& v);

    friend Vector operator -(const Vector& v);
    friend Vector operator +(const Vector &v1, const Vector &v2);
    friend Vector operator -(const Vector &v1, const Vector &v2);
    friend double operator *(const Vector &v1, const Vector &v2);
    friend Vector operator* (const Vector &v,  const double mul);
    friend Vector operator* (const double mul, const Vector& v);

    Vector& operator +=(const Vector& v1)
    {
        m_x += v1.m_x;
        m_y += v1.m_y;
        m_z += v1.m_z;

        return *this;
    }

    Vector& operator -=(const Vector& v1)
    {
        m_x -= v1.m_x;
        m_y -= v1.m_y;
        m_z -= v1.m_z;

        return *this;
    }

    Vector& operator*= (const double mul)
    {
        set(m_x * mul, m_y * mul, m_z * mul);
        return *this;
    }

   
private:
    double m_x, m_y, m_z = NAN;
    mutable double m_len = NAN;

    friend class  Graphics;

};



class Vector_posed 
{
    Vector m_point;
    Vector m_vector;

    public:

        Vector_posed():
            m_point(),
            m_vector()
            {}
        
        Vector_posed(const Vector& r, const Vector& v):
            m_point (r),
            m_vector(v)
            {}

        Vector_posed(const Vector_posed&) = default;
        Vector_posed(Vector_posed&&)      = default;

        Vector_posed& operator= (const Vector_posed&)  = default; //copy assignment
        Vector_posed& operator= (Vector_posed&&)       = default; //move assignment

        void set_point(const Vector& r)
            {
                m_point = r;
            }

        void set_vector(const Vector& v)
            {
                m_vector = v;
            }

        void rotate_z(const double rad_angle)
            {
                m_vector.rotate_z(rad_angle);
            }

        void rotate_z(const double sin, const double cos)
            {
                m_vector.rotate_z(sin, cos);
            }

        Vector vector() const { return m_vector; }
        Vector point()  const { return m_point;  }

        Vector_posed& operator*= (const double mul)
            {
                m_vector *= mul;
                return *this;
            }
        
        Vector_posed& operator+= (const Vector& v)
            {
                m_vector += v;
                return *this;
            }
        
        Vector_posed operator-()
            {
                return Vector_posed {m_point, - m_vector};
            }

        double len()
            {
                return m_vector.len();
            }

        void normalize()
            {
                m_vector.normalize();
            }

        void set_dir(const Vector& dir)
            {
                set_vector(dir - m_point);
            }
};


#endif