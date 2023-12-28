#include <SFML/Graphics.hpp>
#include "include/Circle.hpp"
#include "include/Rectangle.hpp"
#include <memory>
#include <vector>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dancing shapes");

    std::vector<std::unique_ptr<Figure>> figures;
    figures.push_back(std::make_unique<Circle>(100.0f, 300.0f, 200.0f, sf::Color::Green));
    figures.push_back(std::make_unique<Rectangle>(140.0f,140.0f,330.0f,230.0f,sf::Color::Yellow));
    figures.push_back(std::make_unique<Circle>(100.0f,3.0f,300.0f,200.0f,sf::Color::Red));
    figures.push_back(std::make_unique<Circle>(5.0f, 395.0f, 295.0f, sf::Color::Blue));

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