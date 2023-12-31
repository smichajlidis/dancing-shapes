#ifndef FIGUREMANAGER_HPP_
#define FIGUREMANAGER_HPP_

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Figure.hpp"

class FigureManager {
    std::vector<std::shared_ptr<Figure>> figures;
    std::vector<std::string> figuresNames;
    std::string activeFigureName {"circle"};

public:
    void swapFigures(const sf::Event& event);
    void addFigure(std::shared_ptr<Figure>, std::string);
    void setActiveFigureName();
    void update(const sf::Event& event);
    void draw(sf::RenderWindow& window) const;

    FigureManager();
    ~FigureManager();
};

#endif