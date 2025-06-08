#pragma once

#include "animation.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/System/Vector2.hpp>

class Guy {
private:
	sf::Texture* m_texture;
	sf::Sprite* m_sprite;
	Animation* m_animMoving;
	Animation* m_animStanding;
	bool m_moving;
public:
	sf::Vector2f position;

	Guy();
	~Guy();
	void move();
	void draw(sf::RenderWindow& window);
};
