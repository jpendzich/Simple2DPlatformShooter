#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

int main()
{
    auto window = sf::RenderWindow(sf::VideoMode({1600, 900}), "CMake SFML Project");
    window.setFramerateLimit(144);

	sf::RectangleShape rect(sf::Vector2f(100, 100));
	rect.setFillColor(sf::Color(255, 0, 0, 255));

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
        }

        window.clear(sf::Color(255, 255, 255, 255));
		window.draw(rect);

        window.display();
    }
}
