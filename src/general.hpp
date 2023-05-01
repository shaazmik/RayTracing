#ifndef CLOCK_H
#define CLOCK_H

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "./Vector/vector.hpp"
#include "./Coordinate_system/coordinate.hpp"
#include "./Sphere/sphere.hpp"

const int Width  = 1920;
const int Height = 1080;

#define $$ fprintf(stdout, "%d\n", __LINE__);


class Graphics
{
public:
    Graphics(const int width, const int height): m_width(Width), m_height(Height)
    {
        m_window.create(sf::VideoMode(width, height), "Paramon_64");
        m_winXCenter = width / 2;
        m_winYCenter = height/ 2;
    }
    
    Graphics() = default;
    
    ~Graphics()
    {
        m_window.clear();
    }

    sf::RenderWindow m_window;

    void printCoordinateSystem(class CoordinateSystem& decartSys, int width, int height);

    void printVector(class Vector vector, class CoordinateSystem decartSys, double xPlace, double yPlace);

    void rayCastingSphere(class Sphere sphere, class CoordinateSystem& decartSys);

    void launchRayCasting(class Sphere sphere, class CoordinateSystem coord);

    double convertPixXCoord(int pixPos, class CoordinateSystem coord);

    double convertPixYCoord(int pixPos, class CoordinateSystem coord);

    void cleanWindow();

private:

    const int m_width = Width, m_height = Height;
    int m_winXCenter = Width/2;
    int m_winYCenter = Height/2;

    int m_xLight, m_yLight, m_zLight = 0;
    
    static const int m_DefaultZ = 500;

};


#endif