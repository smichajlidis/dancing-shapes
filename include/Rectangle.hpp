#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_
#include <SFML/Graphics.hpp>
#include <memory>
#include "Figure.hpp"

class Rectangle: public Figure {
public:
    Rectangle(float, float, float, float, sf::Color);
};

#endif