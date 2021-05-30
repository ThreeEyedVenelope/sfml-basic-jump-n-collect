#include "Coin.h"

Coin::Coin(sf::Vector2f position) {
	m_texture.loadFromFile("graphics/Coinx8.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(position);
}


sf::Sprite Coin::getSprite() {
	return m_sprite;
}

void Coin::position(sf::Vector2f position) {
	m_sprite.setPosition(position);
}
