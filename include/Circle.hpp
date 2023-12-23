#ifndef _CIRCLE_HPP_
#define _CIRCLE_HPP_
#include <SFML/Graphics.hpp>
#include "Figure.hpp"
//#include "Create_shapes.hpp"

class Circle: public Figure {
private:
    sf::CircleShape shape;
public:
    virtual void setShape(float pos_x, float pos_y, sf::Color color) override;
    virtual void draw(sf::RenderWindow& window) const override;
    virtual void move() override;
    Circle(float);
};

#endif