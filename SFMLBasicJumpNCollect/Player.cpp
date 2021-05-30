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

bool Player::collidingWithGround(Ground& ground) {
	if (m_sprite.getGlobalBounds().intersects(ground.getSprite().getGlobalBounds())) {
		return true;
	}
	else {
		return false;
	}
}

bool Player::collidingWithCoin(Coin* coin) {
	if (m_sprite.getGlobalBounds().intersects(coin->getSprite().getGlobalBounds())) {
		return true;
	}
	else {
		return false;
	}
}

void Player::goRight() {
	m_movingRight = true;
}

void Player::stopRight() {
	m_movingRight = false;
}

void Player::goLeft() {
	m_movingLeft = true;
}

void Player::stopLeft() {
	m_movingLeft = false;
}

void Player::goJump(float groundHeight) {
	m_jumping = true;
}

void Player::stopJump() {
	m_jumping = false;
}

void Player::update(sf::Time t, sf::Vector2f windowSize, float groundHeight, float gravity) {
	m_position = m_sprite.getPosition();

	if (m_movingRight) {
		if ((m_sprite.getPosition().x + m_texture.getSize().x / 2) < windowSize.x) {
			m_position.x += m_speed * t.asSeconds();
		}
	}
	else if (m_movingLeft) {
		if ((m_sprite.getPosition().x - m_texture.getSize().x / 2) > 0) {
			m_position.x -= m_speed * t.asSeconds();
		}
	}

	if (m_jumping) {
		if ((m_sprite.getPosition().y - m_texture.getSize().y / 2) > 0) {
			m_position.y -= m_jumpSpeed * t.asSeconds();
		}
	}

	if ((m_sprite.getPosition().y + m_texture.getSize().y / 2) < groundHeight && m_jumping == false) {
		m_position.y += gravity * t.asSeconds();
	}

	m_sprite.setPosition(m_position);
}
