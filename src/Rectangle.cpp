#include "../include/Rectangle.hpp"

Rectangle::Rectangle(float width, float height, sf::Color color)
    : Figure(std::make_unique<sf::RectangleShape>(sf::Vector2f(width,height))) {
    shape->setPosition(400, 300);
    shape->setFillColor(color);
    shape->setOrigin(width/2, height/2);
}