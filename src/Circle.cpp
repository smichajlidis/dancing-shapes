#include "../include/Circle.hpp"

void Circle::setShape(float pos_x, float pos_y, sf::Color color) {
    shape.setPosition(pos_x, pos_y);
    shape.setFillColor(color);
    }

void Circle::draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

Circle::Circle(float value) {
 //   sf::CircleShape temp {100.0f};
    shape = sf::CircleShape {value};
}