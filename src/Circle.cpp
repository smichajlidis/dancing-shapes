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