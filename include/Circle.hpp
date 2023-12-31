#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include "Figure.hpp"

class Circle : public Figure {

public:
    // Constructor for a circle with a given radius and color
    Circle(float radius, sf::Color color);

    // Constructor for a circle with a given radius, point count, and color
    Circle(float radius, size_t pointCount, sf::Color color);

    // Implementation of the pure virtual function to change the size of the circle
    virtual void changeSize() override;
};

#endif
