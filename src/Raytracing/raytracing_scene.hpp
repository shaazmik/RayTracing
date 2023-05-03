#ifndef RAYTRACING_SCENE
#define RAYTRACING_SCENE

#include "./Scene_objects/scene_objects.hpp"
#include "../Widget/widget.hpp"
#include "../Graphics/graphics.hpp"
#include "../log/log.hpp"

class RayTracingScene : public Widget
{
    public:
        RayTracingScene(unsigned int sphereCount): m_sphereArrCapacity(sphereCount), Widget()
        {
            m_sphereArr = new Sphere*[m_sphereArrCapacity];
            m_pixels    = new sf::Uint8 [m_height * m_width * 4];
        }

        RayTracingScene(): Widget()
        {
            m_pixels    = new sf::Uint8 [m_height * m_width * 4];
        }

        ~RayTracingScene()
        {
            delete[] m_sphereArr;
            delete[] m_pixels;
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

        void setCapacity(unsigned int capacity)
        {
            if (m_sphereArr == nullptr && capacity > 0)
            {
                m_sphereArrCapacity = capacity;
                m_sphereArr = new Sphere*[capacity];
            }
            else
            {
                LOG_MSG("[ERROR]: Scene memory is already allocated");
                logPrintVar(m_sphereArr);
                assert(0);
            }
        }

        void deleteSphere()
        {
            m_sphereCount--;
            m_sphereArr[m_sphereCount] = nullptr;
        }

    private:

        sf::Uint8* m_pixels = nullptr;
        unsigned int m_sphereArrCapacity    = 0;
        unsigned int m_sphereCount          = 0;
        Sphere** m_sphereArr = nullptr;
};


#endif