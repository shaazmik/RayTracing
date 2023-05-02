#include "./graphics.hpp"

void PGL::Graphics::setSize(sf::RectangleShape& widget, const unsigned int width, const int unsigned height)
{
    widget.setSize(sf::Vector2f(width, height));
}

void PGL::Graphics::setFillColor(sf::RectangleShape& widget, PsColor& color)
{
    widget.setFillColor(color.m_currentClr);
}

sf::Vector2f PGL::Graphics::getPosition(sf::RectangleShape* widget)
{
    return widget->getPosition();
}

void PGL::Graphics::move(sf::RectangleShape& widget, float xOffset, float yOffset)
{   
    widget.move(xOffset, yOffset);
}