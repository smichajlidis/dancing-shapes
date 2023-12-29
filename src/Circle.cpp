#include "../include/Circle.hpp"

Circle::Circle(float radius, sf::Color color)
    :    Figure(std::make_unique<sf::CircleShape>(radius)) {
    shape->setOrigin(radius, radius);
    shape->setPosition(400, 300);
    shape->setFillColor(color);
    
}

// Constructor for a triangle

Circle::Circle(float radius, size_t pointCount, sf::Color color)
    :   Figure(std::make_unique<sf::CircleShape>(radius, pointCount)) {
    shape->setOrigin(radius, radius);
    shape->setPosition(400, 300);
    shape->setFillColor(color);
    
}