#include <SFML/Graphics.hpp>
#include "include/Circle.hpp"
#include "include/Rectangle.hpp"
#include "include/FigureManager.hpp"
#include <memory>
#include <vector>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Active figure: CIRCLE");
    FigureManager figures;

    // Add different figures to the manager
    figures.addFigure(std::make_shared<Circle>(100.0f, sf::Color::Green), "circle");
    figures.addFigure(std::make_shared<Rectangle>(140.0f, 140.0f, sf::Color::Yellow), "rectangle");
    figures.addFigure(std::make_shared<Circle>(100.0f, 3.0f, sf::Color::Red), "triangle");
    figures.addFigure(std::make_shared<Circle>(5.0f, sf::Color::Blue), "point");
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                // Change the order in which figures are displayed
                figures.swapFigures(event);
            }
            // Switch between figures
            figures.setActiveFigureName(window);
        }
         // Update the state of figures (move, rotate, etc.)
        figures.update(event);
        window.clear();
        figures.draw(window);
    }

    return 0;
}