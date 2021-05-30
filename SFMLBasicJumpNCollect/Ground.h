#pragma once
#include <SFML/Graphics.hpp>

class Ground {
public:
	Ground(sf::Vector2f windowSize);

	sf::Sprite getSprite();

private:
	sf::Texture m_texture;
	sf::Sprite m_sprite;
	sf::Vector2f m_position;
};