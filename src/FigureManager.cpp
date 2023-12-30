#include "../include/FigureManager.hpp"

void FigureManager::addFigure(std::shared_ptr<Figure> figure) {
    figures.push_back(std::move(figure));
}

void FigureManager::setActiveFigureIndex() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::C)) {
   		activeFigureIndex = 0;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R)) {
   		activeFigureIndex = 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T)) {
   		activeFigureIndex = 2;  
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
   		activeFigureIndex = 3;
    }
}

void FigureManager::update() const {
    std::shared_ptr<Figure> active = figures.at(activeFigureIndex);
    active->move();
    active->rotate();
    active->changeSize();
}

void FigureManager::draw(sf::RenderWindow& window) const {
    window.clear();
    for (auto& f: figures)
        f->draw(window);
    window.display();
}

FigureManager::FigureManager() {}

FigureManager::~FigureManager() {}