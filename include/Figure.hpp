#ifndef _FIGURE_HPP_
#define _FIGURE_HPP_
#include <SFML/Graphics.hpp>

class Figure {
public:
    virtual void setShape(float pos_x, float pos_y, sf::Color color) = 0;
    virtual void draw(sf::RenderWindow& window) const = 0;
    virtual void move() = 0;
    virtual ~Figure() {};
};

#endif