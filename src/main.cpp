#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Vector2.hpp>
#include "guy.hpp"

int main() {
    auto window = sf::RenderWindow(sf::VideoMode({1600, 900}), "CMake SFML Project");
    window.setFramerateLimit(144);
	window.setTitle("2D Shooter Platformer");

	Guy guy = Guy();
	std::cout << sizeof(Guy);

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
		guy.move();

        window.clear(sf::Color(255, 255, 255, 255));
		guy.draw(window);

        window.display();
    }
}
