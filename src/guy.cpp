#include "guy.hpp"
#include "animation.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/Window.hpp>
#include <iostream>

Guy::Guy() : 
m_texture(new sf::Texture("res/guy.bmp")), 
m_sprite(new sf::Sprite(*m_texture)) {
	position = {0, 0};
	m_moving = false;

	m_animMoving = new Animation(*m_texture, *m_sprite, sf::IntRect({0, 0}, {32, 32}), 1, 2);
	m_animStanding = new Animation(*m_texture, *m_sprite, sf::IntRect({0, 0}, {32, 32}), 0);
}

Guy::~Guy() {
	delete m_animMoving;
	delete m_animStanding;
	delete m_texture;
	delete m_sprite;
}

void Guy::move() {
	float dx = 0;
	float dy = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		dy -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		dx -= 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		dy += 2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		dx += 2;
	}

	m_moving = dx != 0 || dy != 0;
	position.x += dx;
	position.y += dy;
}

void Guy::draw(sf::RenderWindow& window) {
	m_sprite->setPosition(position);

	if (m_moving) {
		m_animMoving->play();
		std::cout << "moving\n";
	} else {
		m_animStanding->play();
		std::cout << "not moving\n";
	}
	m_animMoving->draw();
	m_animStanding->draw();

	window.draw(*m_sprite);
}
