#pragma once
#include <SFML/Graphics.hpp>

class Coin {
public:
	Coin(sf::Vector2f position);

	sf::Sprite getSprite();

	void position(sf::Vector2f position);

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite; 
	sf::Vector2f m_position;
};
