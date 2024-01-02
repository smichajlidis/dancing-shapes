#include "../include/Figure.hpp"

// Virtual function to draw the figure on a given window
void Figure::draw(sf::RenderWindow& window) const {
    window.draw(*shape);
}

// Virtual function to move the figure based on keyboard input
void Figure::move() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        shape->setPosition(shape->getPosition().x - 1.f, shape->getPosition().y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        shape->setPosition(shape->getPosition().x + 1.f, shape->getPosition().y);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        shape->setPosition(shape->getPosition().x, shape->getPosition().y - 1.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        shape->setPosition(shape->getPosition().x, shape->getPosition().y + 1.f);
}

// Virtual function to rotate the figure based on keyboard input
void Figure::rotate() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
        shape->rotate(-1.0f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
        shape->rotate(1.0f);
};