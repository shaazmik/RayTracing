#ifndef Factory_HPP
#define Factory_HPP

#include "../Widget/widget.hpp"
#include "../Widget_manager/widget_manager.hpp"
#include "../Abstract_button/abstract_button.hpp"
#include "../Color_button/color_button.hpp"
#include "../Raytracing/raytracing_scene.hpp"
#include "../Graphics/graphics.hpp"
#include "../log/log.hpp"


class Factory 
{
    private:
        inline static Factory* instancePtr = nullptr;
        Factory() = default;

        Non_trans_sphere** m_sphereArr = nullptr;
        unsigned int m_sphereArrCapacity = 0;
        unsigned int m_sphereArrCount    = 0;

        Widget** m_widgetArr = nullptr;
        unsigned int m_widgetArrCapacity = 0;
        unsigned int m_widgetArrCount    = 0;

        template <typename T>
        T* createWidget()
        {
            if (m_widgetArrCount < m_widgetArrCapacity)
            {
                T* value = new T();
                m_widgetArr[m_widgetArrCount] = static_cast<Widget*>(value);
                m_widgetArrCount++;
                return value;
            }
            else
            {
                LOG_MSG("[ERROR]: WIDGET NUMBERS OVERFLOW");
                LOG_CUR_VAR(m_widgetArrCount);
                LOG_CUR_VAR(m_widgetArrCapacity);
                assert(0);
                return nullptr;
            }
        }
    
    public:
        ~Factory()
        {
            $;
            for (int i = 0; i < m_widgetArrCount; i++)
            {
                delete m_widgetArr[i];
            }

            for (int i = 0; i < m_sphereArrCount; i++)
            {
                delete m_sphereArr[i];
            }

            delete[] m_widgetArr;
            delete[] m_sphereArr;
        }

        Factory(const Factory& obj) = delete;

        static Factory* getInstance()
        {
            if (instancePtr == nullptr)
            {
              instancePtr = new Factory();

              return instancePtr;
            }
            else
            {
              return instancePtr;
            }
        }

        void setWidgetCapacity(unsigned int capacity)
        {
            if (m_widgetArr == nullptr && capacity > 0)
            {
                m_widgetArrCapacity = capacity;
                m_widgetArr = new Widget*[capacity];
            }
            else
            {
                LOG_MSG("[ERROR]: Widget memory is already allocated");
                logPrintVar(m_widgetArr);
                assert(0);
            }
        }

        void setSphereCapacity(unsigned int capacity)
        {
            if (m_sphereArr == nullptr && capacity > 0)
            {
                m_sphereArrCapacity = capacity;
                m_sphereArr = new Non_trans_sphere*[capacity];
            }
            else
            {
                LOG_MSG("[ERROR]: Sphere memory is already allocated");
                logPrintVar(m_sphereArr);
                assert(0);
            }
        }

        Widget* makeWidget()
        {
            return (createWidget<Widget>());
        }

        AbstractButton* makeAbstractButton()
        {
            return (createWidget<AbstractButton>());
        }

        WidgetManager* makeWidgetManager()
        {
            return (createWidget<WidgetManager>());
        }

        RayTracingScene* makeRayTracingScene()
        {
            return (createWidget<RayTracingScene>());
        }

        SphereColorButton* makeSphereColorButton()
        {
            return (createWidget<SphereColorButton>());
        }

        // Non_trans_sphere* makeSphere()
        // {
        //     if (m_sphereArrCount < m_sphereArrCapacity)
        //     {
        //         m_sphereArr[m_sphereArrCount] = new ();
        //         m_sphereArrCount++;
        //         return m_sphereArr[m_sphereArrCount - 1];
        //     }
        //     else
        //     {
        //         LOG_MSG("[ERROR]: SPHERE NUMBERS OVERFLOW");
        //         LOG_CUR_VAR(m_widgetArrCount);
        //         LOG_CUR_VAR(m_widgetArrCapacity);
        //         assert(0);
        //         return nullptr;
        //     }
        // }
};



#endif