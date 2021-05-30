#pragma once
#include <SFML/Graphics.hpp>
#include "Ground.h"

class Player {
public:
	Player(Ground ground);

	sf::Sprite getSprite();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
};