#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>
#include "Figure.hpp"

class Rectangle : public Figure {
public:
    // Constructor for a rectangle with given width, height, and color
    Rectangle(float width, float height, sf::Color color);

    // Implementation of the pure virtual function to change the size of the rectangle
    virtual void changeSize() override;
};

#endif
