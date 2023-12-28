#include "../include/Rectangle.hpp"

void Rectangle::draw(sf::RenderWindow& window) const {
        window.draw(shape);
    }

Rectangle::Rectangle(float val1, float val2, float pos_x, float pos_y, sf::Color color) {
    shape = sf::RectangleShape {sf::Vector2f (val1, val2)};
    shape.setPosition(pos_x, pos_y);
    shape.setFillColor(color);
}

void Rectangle::move() {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
   			 shape.setPosition(shape.getPosition().x - 1.f, shape.getPosition().y);	    
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
   			shape.setPosition(shape.getPosition().x + 1.f, shape.getPosition().y);
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
   			 shape.setPosition(shape.getPosition().x, shape.getPosition().y-1.f);	       
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
   			 shape.setPosition(shape.getPosition().x, shape.getPosition().y+1.f);	 
    }

void Rectangle::rotate() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q)) 
   			 shape.setRotation(shape.getRotation() - 1);	    
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
   			shape.setRotation(shape.getRotation() + 1);
}