#ifndef RAYTRACING_SCENE
#define RAYTRACING_SCENE

#include "../Sphere/sphere.hpp"
#include "../log/log.hpp"

class RayTracingScene
{
    public:
        RayTracingScene(unsigned int sphereCount): m_sphereArrCapacity(sphereCount)
        {
            m_sphereArr = new Sphere*[m_sphereArrCapacity];
        }

        ~RayTracingScene()
        {
            delete[] m_sphereArr;
        }

        void addSphere(Sphere* sphere)
        {
            if (m_sphereCount < m_sphereArrCapacity)
            {
                m_sphereArr[m_sphereCount] = sphere;
                m_sphereCount++;
            }
            else
            {
                LOG_CUR_VAR(m_sphereCount);
                LOG_CUR_VAR(m_sphereArrCapacity);
            }
        };

        void deleteSphere()
        {
            m_sphereCount--;
            m_sphereArr[m_sphereCount] = nullptr;
        }

    private:
        unsigned int m_sphereArrCapacity    = 0;
        unsigned int m_sphereCount          = 0;
        Sphere** m_sphereArr = nullptr;
};


#endif