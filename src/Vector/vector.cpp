#include "vector.hpp"


double dotProduct(const Vector& v1, const Vector& v2)
{
    return (v2.m_x * v1.m_x + v2.m_y * v1.m_y + v2.m_z * v1.m_z);
}


Vector getNormal(const Vector& v1)
{
    Vector normal(0, - v1.m_y, v1.m_z);

    normal.m_x = normal.m_y * normal.m_y / v1.m_x;

    normal.synchronization();

    double sqrtLen = sqrt(normal.m_sqrLen);

    normal.m_x = normal.m_x / sqrtLen;
    normal.m_y = normal.m_y / sqrtLen;
    normal.m_z = normal.m_z / sqrtLen;

    normal.synchronization();
    return normal;
}



void Vector::mulVector(double n_times)
{
    m_x *= n_times;
    m_y *= n_times;
    m_z *= n_times;

    m_sync = false;
}



void Vector::divVector(double n_times)
{
    if (isEqualFloat(n_times, 0))
    {
        fprintf(stderr, "Can't div on zero\n");
        return;
    }
    m_x /= n_times;
    m_y /= n_times;
    m_z /= n_times;

    m_sync = false;
}


void Vector::synchronization()
{
    m_sqrLen = m_x*m_x + m_y*m_y + m_z*m_z;
    m_sync   = true;
}


bool Vector::isEqualFloat(double first, double second)
{
    return ((first - second) < Epsylon);
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


Vector operator *(const Vector &v1, const Vector &v2)
{
    Vector result(v1.m_y * v2.m_z - v1.m_z * v2.m_y,
                  v1.m_z * v2.m_x - v1.m_x * v2.m_z,
                  v1.m_x * v2.m_y - v1.m_y * v2.m_x);

    return result;
}

void Vector::rotate(double rad)
{

}