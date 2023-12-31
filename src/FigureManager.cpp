#include "../include/FigureManager.hpp"
#include <iostream>

void FigureManager::swapFigures(const sf::Event& event) {
    // Find the index of the active figure in the vector
    size_t count {0};
    for (std::string s: figuresNames) {
        if (s == activeFigureName)
            break;
        ++count;
    }

    // Backup the active figure and its name
    std::shared_ptr<Figure> figureBuff = figures.at(count);
    std::string nameBuff = figuresNames.at(count);

    // Remove the active figure from the vector
    figures.erase(figures.begin() + count);
    figuresNames.erase(figuresNames.begin() + count);

    // Handle figure swapping based on the pressed key
    switch (event.key.code) {
        case sf::Keyboard::D:
            if (count < figures.size()) count+=1;
            break;
        case sf::Keyboard::A:
            if (count > 0) count-=1;
            break;
        default: break;
    }

    // Insert the active figure back into the vector at the new position
    figures.insert(figures.begin() + count, figureBuff);
    figuresNames.insert(figuresNames.begin() + count, nameBuff);
}

void FigureManager::addFigure(std::shared_ptr<Figure> figure, std::string name) {
    // Add a new figure and its name to the vector
    figures.push_back(std::move(figure));
    figuresNames.push_back(name);
}

void FigureManager::setActiveFigureName(sf::RenderWindow& window) {
    // Set the active figure name based on the pressed key and update the window title
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
        activeFigureName = "circle";
        window.setTitle("Active figure: CIRCLE");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
        activeFigureName = "rectangle";
        window.setTitle("Active figure: RECTANGLE");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
        activeFigureName = "triangle";  
        window.setTitle("Active figure: TRIANGLE");
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
        activeFigureName = "point";
        window.setTitle("Active figure: POINT");
    }
}

void FigureManager::update(const sf::Event& event) {
    // Find the index of the active figure in the vector
    size_t count {0};
    for (std::string s: figuresNames) {
        if (s == activeFigureName) break;
        ++count;
    }

    // Get the active figure
    std::shared_ptr<Figure> active = figures.at(count);

    // Update the active figure (move, resize, rotate)
    active->move();
    active->changeSize();
    active->rotate();
}

void FigureManager::draw(sf::RenderWindow& window) const {
    // Clear the window and draw all figures
    window.clear();
    for (auto& f: figures)
        f->draw(window);
    window.display();
}

FigureManager::FigureManager() {}

FigureManager::~FigureManager() {}
