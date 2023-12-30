#include <SFML/Graphics.hpp>
#include "include/Circle.hpp"
#include "include/Rectangle.hpp"
#include "include/FigureManager.hpp"
#include <memory>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dancing shapes");
    FigureManager figures;

    figures.addFigure(std::make_shared<Circle>(100.0f, sf::Color::Green));
    figures.addFigure(std::make_shared<Rectangle>(140.0f, 140.0f, sf::Color::Yellow));
    figures.addFigure(std::make_shared<Circle>(100.0f, 3.0f, sf::Color::Red));
    figures.addFigure(std::make_shared<Circle>(5.0f, sf::Color::Blue));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            figures.setActiveFigureIndex();
        }

        figures.update();
        figures.draw(window);
    }

    return 0;
}