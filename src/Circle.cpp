#include "../include/Circle.hpp"

void Circle::changeSize() {
    // Increase the size of the circle when 'W' key is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        sf::CircleShape* circleShape = dynamic_cast<sf::CircleShape*>(shape.get());
        if (circleShape) {
            float currentRadius = circleShape->getRadius();
            circleShape->setRadius(currentRadius + 1.0f);
            sf::Vector2f currentOrigin = circleShape->getOrigin();
            circleShape->setOrigin(currentOrigin + sf::Vector2f(1.0f, 1.0f));
        }
    }

    // Decrease the size of the circle when 'S' key is pressed
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
    : Figure(std::make_unique<sf::CircleShape>(radius)) {
    // Set the origin, position, and fill color for the circle
    shape->setOrigin(radius, radius);
    shape->setPosition(400, 300);
    shape->setFillColor(color);
}

Circle::Circle(float radius, size_t pointCount, sf::Color color)
    : Figure(std::make_unique<sf::CircleShape>(radius, pointCount)) {
    // Set the origin, position, and fill color for the circle (for triangles)
    shape->setOrigin(radius, radius);
    shape->setPosition(400, 300);
    shape->setFillColor(color);
}
