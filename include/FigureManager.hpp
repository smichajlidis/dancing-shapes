#ifndef FIGUREMANAGER_HPP_
#define FIGUREMANAGER_HPP_

#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>
#include "Figure.hpp"

class FigureManager {
    std::vector<std::shared_ptr<Figure>> figures;  // Vector to store smart pointers to figures
    std::vector<std::string> figuresNames;         // Vector to store names of figures
    std::string activeFigureName {"circle"};       // Name of the currently active figure

public:
    // Function to swap figures based on a key event
    void swapFigures(const sf::Event& event);

    // Function to add a new figure to the manager
    void addFigure(std::shared_ptr<Figure>, std::string);

    // Function to set the active figure name based on the pressed key and update the window title
    void setActiveFigureName(sf::RenderWindow& window);

    // Function to update the state of the active figure (e.g., move, resize, rotate)
    void update(const sf::Event& event);

    // Function to draw all figures on a given window
    void draw(sf::RenderWindow& window) const;

    // Constructor
    FigureManager();

    // Destructor
    ~FigureManager();
};

#endif
