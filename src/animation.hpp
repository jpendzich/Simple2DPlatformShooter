#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Clock.hpp>
#include <vector>

class Animation {
private:
	sf::Texture& m_texture;
	sf::IntRect m_texRect;
	sf::Sprite& m_sprite;
	sf::Clock m_clock;
	std::vector<int> m_animQueue;
	int m_animPos;

	void setNextInQueue();
public:
	template<typename... Queue>
	Animation(sf::Texture &texture, sf::Sprite &sprite, sf::IntRect texRect, Queue... queue) :
	m_texture(texture),
	m_sprite(sprite) {
		m_animQueue = {queue...};
		m_texRect = sf::IntRect(texRect);
		m_animPos = 0;
		setNextInQueue();
	}

	void play();
	void stop();
	void draw();
};
