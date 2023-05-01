#include "general.hpp"
#include <stdio.h>


const double zViewer = 400;

void Graphics::printCoordinateSystem(class CoordinateSystem& decartSys, int width, int height)
{
    decartSys.m_height = height;
    decartSys.m_width  = width;

    if (abs(decartSys.m_xMax) < Epsylon)
    {
        decartSys.m_xScale = 0;
    }
    else
    {
        decartSys.m_xScale = width/(2 * decartSys.m_xMax);
    }

    if (abs(decartSys.m_yMax) < Epsylon)
    {
        decartSys.m_yScale = 0;
    } 
    else
    {
        decartSys.m_yScale = height/(decartSys.m_yMax * 2);
    }

    sf::RectangleShape rectangle(sf::Vector2f(width, height));

    decartSys.m_winX0 = m_winXCenter + decartSys.m_xScale*decartSys.m_x0;
    decartSys.m_winY0 = m_winYCenter - decartSys.m_yScale*decartSys.m_y0;
    
    rectangle.setPosition(decartSys.m_winX0 - width/2, decartSys.m_winY0 - height/2);
    rectangle.setFillColor(sf::Color(decartSys.m_colorRed, decartSys.m_colorGreen, decartSys.m_colorBlue));

    m_window.draw(rectangle);
}

void Graphics::printVector(class Vector vector, class CoordinateSystem decartSys, double xPlace, double yPlace)
{
    double x0 = decartSys.m_winX0 + (xPlace - vector.m_x)*decartSys.m_xScale; 
    double y0 = decartSys.m_winY0 - (yPlace - vector.m_y)*decartSys.m_yScale;

    double xPlaceCur = decartSys.m_winX0 + xPlace*decartSys.m_xScale;
    double yPlaceCur = decartSys.m_winY0 - yPlace*decartSys.m_yScale;

    sf::Vertex line[]
    {
        sf::Vertex(sf::Vector2f(x0, y0)),
        sf::Vertex(sf::Vector2f(xPlaceCur, yPlaceCur))
    };
    m_window.draw(line, 2, sf::Lines);
    
    m_window.display();
}


void Graphics::rayCastingSphere(class Sphere sphere, class CoordinateSystem& decartSys)
{
    printCoordinateSystem(decartSys, m_width, m_height);

    sf::Texture texture {};
    texture.create (m_width, m_height);
    
    sf::Sprite sprite (texture);

    double xLight  = convertPixXCoord(m_xLight, decartSys);
    double yLight  = convertPixYCoord(m_yLight, decartSys);
    double zLight  = m_zLight; 

    size_t pixelIndex = 0;

    double sqrR = sphere.m_R * sphere.m_R;

    for (int y = decartSys.m_yMax; y > -decartSys.m_yMax; y--)
    {
        for (int x = -decartSys.m_xMax; x < decartSys.m_xMax; x++)
        {
            decartSys.pixels[pixelIndex++] = sphere.m_colorRed;  
            decartSys.pixels[pixelIndex++] = sphere.m_colorGreen;   
            decartSys.pixels[pixelIndex++] = sphere.m_colorBlue;

            double z = sqrR - x*x - y*y;

            double Irgb = 0;
            double Amb  = 0.1;
            double Dif  = 0;

            if (z >= 0)
            {
                Irgb += Amb;

                z = sqrt(z);

                Vector lightVec(xLight - x,      yLight - y,      zLight - z);
                Vector normal  (x - sphere.m_x0, y - sphere.m_y0, z - sphere.m_z0);

                double cosPhi = dotProduct(lightVec, normal) / (sqrt(lightVec.m_sqrLen) * sqrt(normal.m_sqrLen));
                
                if (cosPhi < 0)
                {
                    decartSys.pixels[pixelIndex++] = Irgb * 255;
                }
                else
                {
                    Dif  = cosPhi;
                    Irgb+= Dif;

                    if (Irgb > 1) 
                    {
                        Irgb = 1;
                    }

                    decartSys.pixels[pixelIndex++] = Irgb * 255;
                }
            }
            else
            {
                decartSys.pixels[pixelIndex++] = Irgb;
            }
        }
    }

    texture.update(decartSys.pixels);

    m_window.draw(sprite);
}

void Graphics::launchRayCasting(class Sphere sphere, class CoordinateSystem coord)
{
    m_zLight = m_DefaultZ;

    while (m_window.isOpen())
    {   
        sf::Event event;

        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                m_window.close();

            if (event.type == sf::Event::MouseMoved)
            {
                m_xLight = event.mouseMove.x;
                m_yLight = event.mouseMove.y;
            }
            
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::Up)
                {
                    m_zLight += 50;
                }
                else if (event.key.code == sf::Keyboard::Down)
                {
                    m_zLight -= 50;
                }
            }
        }

        rayCastingSphere(sphere, coord);

        m_window.display();
        m_window.clear();
    }
}

void Graphics::cleanWindow()
{
    m_window.clear();
    m_window.display();
}


double Graphics::convertPixXCoord(int pixPos, class CoordinateSystem coord)
{
    if (abs(coord.m_xScale) < Epsylon)
    {
        return 0;
    }
    
    return ((pixPos - m_winXCenter)/coord.m_xScale);
}

double Graphics::convertPixYCoord(int pixPos, class CoordinateSystem coord)
{
    if (abs(coord.m_yScale) < Epsylon)
    {
        return 0;
    }
    
    return ((m_winYCenter - pixPos)/coord.m_yScale);
}
