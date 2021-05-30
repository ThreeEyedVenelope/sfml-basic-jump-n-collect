#include "Ground.h"

Ground::Ground(sf::Vector2f windowSize) {
	m_texture.loadFromFile("graphics/Groundx8.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(windowSize.x / 2, windowSize.y - m_texture.getSize().y / 2);
}

sf::Sprite Ground::getSprite() {
	return m_sprite;
}

sf::Texture Ground::getTexture() {
	return m_texture;
}