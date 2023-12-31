#include "../include/FigureManager.hpp"
#include <iostream>

void FigureManager::swapFigures(const sf::Event& event) {
    
    size_t count {0};
    for (std::string s: figuresNames) {
        if (s == activeFigureName)
            break;
        ++count;
    }
    std::shared_ptr<Figure> figureBuff = figures.at(count);
    std::string nameBuff = figuresNames.at(count);
    figures.erase(figures.begin() + count);
    figuresNames.erase(figuresNames.begin() + count);

    switch (event.key.code) {
        case sf::Keyboard::D:
            if (count < figures.size()) count+=1;
            break;
        case sf::Keyboard::A:
            if (count > 0) count-=1;
            break;
        default: break;
    }

    figures.insert(figures.begin() + count, figureBuff);
    figuresNames.insert(figuresNames.begin() + count, nameBuff);
}

void FigureManager::addFigure(std::shared_ptr<Figure> figure, std::string name) {
    figures.push_back(std::move(figure));
    figuresNames.push_back(name);
}

void FigureManager::setActiveFigureName() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
   		activeFigureName = "circle";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
   		activeFigureName = "rectangle";
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
   		activeFigureName = "triangle";  
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)) {
   		activeFigureName = "point";
    }
}

void FigureManager::update(const sf::Event& event) {

    size_t count {0};
    for (std::string s: figuresNames) {
        if (s == activeFigureName) break;
        ++count;
    }
    std::shared_ptr<Figure> active = figures.at(count);

    active->move();
    active->changeSize();
    active->rotate();

}

void FigureManager::draw(sf::RenderWindow& window) const {
    window.clear();
    for (auto& f: figures)
        f->draw(window);
    window.display();
}

FigureManager::FigureManager() {}

FigureManager::~FigureManager() {}