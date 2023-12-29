#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_
#include <SFML/Graphics.hpp>
#include <memory>
#include "Figure.hpp"

class Circle: public Figure {

public:
    Circle(float, sf::Color); //constructor for a circle
    Circle(float, size_t, sf::Color); //constructor for a triangle
    virtual void changeSize() override;
};

#endif