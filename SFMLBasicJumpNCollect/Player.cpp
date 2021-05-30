#include "Player.h"

Player::Player(Ground ground) {
	m_texture.loadFromFile("graphics/Playerx8.png");
	m_sprite.setTexture(m_texture);
	m_sprite.setOrigin(m_texture.getSize().x / 2, m_texture.getSize().y / 2);
	m_sprite.setPosition(ground.getTexture().getSize().x/2, ground.getSprite().getPosition().y - ground.getTexture().getSize().y/2 - m_texture.getSize().y/2);
}

sf::Sprite Player::getSprite() {
	return m_sprite;
}