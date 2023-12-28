#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_
#include <SFML/Graphics.hpp>
#include "Figure.hpp"

class Circle: public Figure {
private:
    sf::CircleShape shape;
public:
    virtual void draw(sf::RenderWindow& window) const override;
    virtual void move() override;
    Circle(float, float, float, sf::Color); //constructor for a circle
    Circle(float, size_t, float, float, sf::Color); //constructor for a triangle
};

#endif