#include "../include/Circle.hpp"

void Circle::draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

Circle::Circle(float value, float pos_x, float pos_y, sf::Color color) {
    shape = sf::CircleShape {value};
    shape.setPosition(pos_x, pos_y);
    shape.setFillColor(color);
}

// Constructor for a triangle

Circle::Circle(float val1, size_t val2, float pos_x, float pos_y, sf::Color color) {
    shape = sf::CircleShape {val1, val2};
    shape.setPosition(pos_x, pos_y);
    shape.setFillColor(color);
}

void Circle::move() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
   			 shape.setPosition(shape.getPosition().x - 1.f, shape.getPosition().y);	    
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
   			shape.setPosition(shape.getPosition().x + 1.f, shape.getPosition().y);
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
   			 shape.setPosition(shape.getPosition().x, shape.getPosition().y-1.f);	       
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
   			 shape.setPosition(shape.getPosition().x, shape.getPosition().y+1.f);	 
    }

void Circle::rotate() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) 
   			 shape.setRotation(shape.getRotation() - 1);	    
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
   			shape.setRotation(shape.getRotation() + 1);
}