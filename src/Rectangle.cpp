#include "../include/Rectangle.hpp"

Rectangle::Rectangle(float val1, float val2, float pos_x, float pos_y, sf::Color color)
    : Figure(std::make_unique<sf::RectangleShape>(sf::Vector2f(val1,val2))) {
   // shape = sf::RectangleShape {sf::Vector2f (val1, val2)};
    shape->setPosition(pos_x, pos_y);
    shape->setFillColor(color);
}