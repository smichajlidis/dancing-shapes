#include "../include/Rectangle.hpp"

void Rectangle::changeSize() {
    // Increase the size of the rectangle when 'W' key is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        sf::RectangleShape* rectangleShape = dynamic_cast<sf::RectangleShape*>(shape.get());
        if (rectangleShape) {
            sf::Vector2f currentSize = rectangleShape->getSize();
            rectangleShape->setSize(sf::Vector2f(currentSize.x + 1.0f, currentSize.y + 1.0f));
            rectangleShape->setOrigin(rectangleShape->getSize() / 2.0f);
        }
    }

    // Decrease the size of the rectangle when 'S' key is pressed
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        sf::RectangleShape* rectangleShape = dynamic_cast<sf::RectangleShape*>(shape.get());
        if (rectangleShape) {
            sf::Vector2f currentSize = rectangleShape->getSize();
            rectangleShape->setSize(sf::Vector2f(std::max(0.0f, currentSize.x - 1.0f), std::max(0.0f, currentSize.y - 1.0f)));
            rectangleShape->setOrigin(rectangleShape->getSize() / 2.0f);
        }
    }
}

Rectangle::Rectangle(float width, float height, sf::Color color)
    : Figure(std::make_unique<sf::RectangleShape>(sf::Vector2f(width, height))) {
    // Set the position, fill color, and origin for the rectangle
    shape->setPosition(400, 300);
    shape->setFillColor(color);
    shape->setOrigin(width / 2, height / 2);
}