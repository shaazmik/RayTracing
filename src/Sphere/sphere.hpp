#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "../my_math.hpp"
#include "../Graphics/pscolor.hpp"
#include "../log/log.hpp"
#include "../Widget/widget.hpp"

const unsigned char defaultRed   = 128;
const unsigned char defaultGreen = 168;
const unsigned char defaultBlue  = 190;
const unsigned char defaultAlp   = 255;

class Sphere
{
public:
    Sphere(double x0, double y0, double z0, double R): m_x0(x0), m_y0(y0), m_z0(z0), m_R(R)
    {
        m_color.SetRGB(defaultRed, defaultGreen, defaultBlue, defaultAlp);
    }

    Sphere()
    {
        m_color.SetRGB(defaultRed, defaultGreen, defaultBlue, defaultAlp);
    }

    void setCenter(int x, int y, int z)
    {
        m_x0 = x;
        m_y0 = y;
        m_z0 = z;
    }

    void setRadius(unsigned int R)
    {
        m_R = R;
    }

    ~Sphere()
    {
        m_x0 = Poison;
        m_y0 = Poison;
        m_z0 = Poison;
        m_R  = Poison;
        m_color.SetRed();
    }

    void setColor(unsigned char Red, unsigned char Green, unsigned char Blue, unsigned char Alp)
    {
        m_color.SetRGB(Red, Green, Blue, Alp);
    }
    
private:
    int m_x0, m_y0, m_z0 = 0;
    unsigned int m_R     = 0;

    PGL::PsColor m_color;
};



class SphereManager
{
public:
    SphereManager(unsigned int size):m_size(size)
    {
        m_sphereArr = new Sphere*[size];
    }
    ~SphereManager()
    {
        delete[] m_sphereArr;
    }

    void addObj(Sphere* sphere)
    {
        if (m_count < m_size)
        {
            m_sphereArr[m_count] = sphere;
            m_count++;
        }
        else
        {
            LOG_CUR_VAR(m_count);
            LOG_CUR_VAR(m_size);
        }
    }

    void deleteObj(unsigned int index)
    {
        if(index >= m_size && index < 0)
        {
            LOG_CUR_VAR(index);
            LOG_CUR_VAR(m_size);
        }
        else
        {
            m_sphereArr[index] = nullptr;
        }     
    }

    void getIndexOnClick()
    {
        $;
    }
private:
    unsigned int m_size  = 0;

protected:
    Sphere** m_sphereArr = nullptr;
    unsigned int m_count = 0;
};

#endif