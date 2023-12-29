#include "../include/Circle.hpp"

void Circle::changeSize() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        sf::CircleShape* circleShape = dynamic_cast<sf::CircleShape*>(shape.get());
        if (circleShape) {
            float currentRadius = circleShape->getRadius();
            circleShape->setRadius(currentRadius + 1.0f);
            sf::Vector2f currentOrigin = circleShape->getOrigin();
            circleShape->setOrigin(currentOrigin + sf::Vector2f(1.0f, 1.0f));
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        sf::CircleShape* circleShape = dynamic_cast<sf::CircleShape*>(shape.get());
        if (circleShape && circleShape->getRadius() > 0) {
            float currentRadius = circleShape->getRadius();
            circleShape->setRadius(std::max(0.0f, currentRadius - 1.0f));
            sf::Vector2f currentOrigin = circleShape->getOrigin();
            circleShape->setOrigin(currentOrigin - sf::Vector2f(1.0f, 1.0f));
        }
    }
}

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