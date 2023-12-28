#ifndef _RECTANGLE_HPP_
#define _RECTANGLE_HPP_
#include <SFML/Graphics.hpp>
#include "Figure.hpp"

class Rectangle: public Figure {
private:
    sf::RectangleShape shape;
public:
    virtual void draw(sf::RenderWindow& window) const override;
    virtual void move() override;
    Rectangle(float, float, float, float, sf::Color);
};

#endif