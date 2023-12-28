#include <SFML/Graphics.hpp>
#include "include/Circle.hpp"
#include <memory>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dancing shapes");

    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Circle>(100.0f, 25.0f, 150.0f, sf::Color::Green));

    std::unique_ptr<Figure>& active = figures.at(0);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        active->move();
        for (auto& f: figures)
            f->draw(window);
        window.display();
    }

    return 0;
}