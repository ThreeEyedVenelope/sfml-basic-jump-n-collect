#pragma once
#include <SFML/Graphics.hpp>
#include "Ground.h"
#include "Coin.h"

class Player {
public:
	Player(Ground ground);

	sf::Sprite getSprite();

	bool collidingWithGround(Ground& ground);
	bool collidingWithCoin(Coin* coin);

	void goLeft();
	void stopLeft();

	void goRight();
	void stopRight();

	void goJump(float groundHeight);
	void stopJump();

	void update(sf::Time t, sf::Vector2f windowSize, float groundHeight, float gravity);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;

	float m_speed = 400.0f;
	float m_jumpSpeed = 550.0f;

	bool m_movingRight = false; 
	bool m_movingLeft = false; 
	bool m_jumping = false;
};