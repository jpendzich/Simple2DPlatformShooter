#include "animation.hpp"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Time.hpp>
#include <iterator>

void Animation::play() {
	if (!m_clock.isRunning()) {
		m_clock.start();
	}
}

void Animation::stop() {
	if (m_clock.isRunning()) {
		m_clock.stop();
	}
}

void Animation::draw() {
	if (m_clock.getElapsedTime().asMilliseconds() >= 100) {
		setNextInQueue();
		m_clock.restart();
	}
}

void Animation::setNextInQueue() {
	m_animPos = ++m_animPos % std::size(m_animQueue);
	int x = m_animQueue[m_animPos] * m_texRect.size.x;
	int y = (x / m_texture.getSize().x) * m_texRect.size.y;
	m_texRect.position.x = x;
	m_texRect.position.y = y;

	m_sprite.setTextureRect(m_texRect);
}
