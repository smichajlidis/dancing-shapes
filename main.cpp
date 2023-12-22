#include <SFML/Graphics.hpp>
//#include "include/Create_shapes.hpp"
#include "include/Circle.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Dancing shapes");
    Circle circle {100.0f};
    circle.setShape(25.0f, 150.0f, sf::Color::Green);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        circle.draw(window);
        window.display();
    }

    return 0;
}