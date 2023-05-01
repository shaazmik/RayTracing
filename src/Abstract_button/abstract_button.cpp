#include "abstract_button.hpp"


void AbstractBtnManager::controller(sf::Event event)
{
    sf::Vector2i position = sf::Mouse::getPosition(m_mainWin->m_window);
    int curX = position.x;
    int curY = position.y;

    for (int i = 0; i < m_count; i++)
    {
        if (m_abstractBtnArr[i]->checkPointInWidget(curX, curY))
        {
            if ((event.mouseButton.button ==  sf::Mouse::Left) && !(m_abstractBtnArr[i]->getPressStatus()))
            {
                m_abstractBtnArr[i]->switchPressStatus();
                if (m_idCurrentBtn >= 0)
                {
                    m_abstractBtnArr[m_idCurrentBtn]->switchPressStatus();
                }
                m_idCurrentBtn = i;
            }
        }
    }

    return;
}