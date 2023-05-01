#ifndef Factory_HPP
#define Factory_HPP

#include "../Widget/widget.hpp"
#include "../Graphics/graphics.hpp"
#include "../log/log.hpp"


class Factory {
    private:
        inline static Factory* instancePtr = nullptr;
        Factory() = default;


        Widget** m_widgetArr = nullptr;
        unsigned int m_widgetArrCapacity = 0;
        unsigned int m_widgetArrCount    = 0;
    
    public:
        ~Factory()
        {
            delete[] m_widgetArr;
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
                LOG_MSG("Widget memory is already allocated");
                logPrintVar(m_widgetArr);
            }
        }

        Widget* makeWidget()
        {
            if (m_widgetArrCount < m_widgetArrCapacity)
            {
                m_widgetArr[m_widgetArrCount] = new Widget;
                m_widgetArrCount++;
            }
            else
            {
                LOG_MSG("ERR: WIDGET NUMBERS OVERFLOW");
                LOG_CUR_VAR(m_widgetArrCount);
                LOG_CUR_VAR(m_widgetArrCapacity);
            }

            return m_widgetArr[m_widgetArrCount - 1];
        }
};



#endif