#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

class Figure {
protected:
    std::unique_ptr<sf::Shape> shape;

public:
    // Virtual function to draw the figure on a given window
    virtual void draw(sf::RenderWindow& window) const;
    // Virtual function to move the figure based on keyboard input
    virtual void move();
    // Virtual function to rotate the figure based on keyboard input
    virtual void rotate();
    // Pure virtual function to change the size of the figure (to be implemented by derived classes)
    virtual void changeSize() = 0;
    // Constructor accepting a unique pointer to an sf::Shape
    Figure(std::unique_ptr<sf::Shape> shape) : shape(std::move(shape)) {};
    // Virtual destructor
    virtual ~Figure() {};
};

#endif
