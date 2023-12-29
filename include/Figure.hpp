#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include <SFML/Graphics.hpp>
#include <memory>

class Figure {
protected:
	std::unique_ptr<sf::Shape> shape;
public:
    virtual void draw(sf::RenderWindow& window) const {
		window.draw(*shape);
	};
    virtual void move() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)) 
   			 shape->setPosition(shape->getPosition().x - 1.f, shape->getPosition().y);	    
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
   			shape->setPosition(shape->getPosition().x + 1.f, shape->getPosition().y);
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
   			 shape->setPosition(shape->getPosition().x, shape->getPosition().y-1.f);	       
	    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
   			 shape->setPosition(shape->getPosition().x, shape->getPosition().y+1.f);	
	};
	virtual void rotate() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Q))
			shape->rotate(-1.0f);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::E))
			shape->rotate(1.0f);
	};
	Figure(std::unique_ptr<sf::Shape> shape) : shape(std::move(shape)) {};
    virtual ~Figure() {};
};

#endif