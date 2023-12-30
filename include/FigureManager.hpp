#ifndef FIGUREMANAGER_HPP_
#define FIGUREMANAGER_HPP_

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Figure.hpp"

class FigureManager {
    std::vector<std::shared_ptr<Figure>> figures;
    int activeFigureIndex {0};

public:
    void addFigure(std::shared_ptr<Figure>);
    void setActiveFigureIndex();
    void update() const;
    void draw(sf::RenderWindow& window) const;

    FigureManager();
    ~FigureManager();
};

#endif