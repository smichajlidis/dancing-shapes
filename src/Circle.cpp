#include "../include/Circle.hpp"

Circle::Circle(float value, float pos_x, float pos_y, sf::Color color)
    :    Figure(std::make_unique<sf::CircleShape>(value)) {
    shape->setPosition(pos_x, pos_y);
    shape->setFillColor(color);
}

// Constructor for a triangle

Circle::Circle(float val1, size_t val2, float pos_x, float pos_y, sf::Color color)
    :   Figure(std::make_unique<sf::CircleShape>(val1, val2)) {
    //shape = sf::CircleShape {val1, val2};
    shape->setPosition(pos_x, pos_y);
    shape->setFillColor(color);
}