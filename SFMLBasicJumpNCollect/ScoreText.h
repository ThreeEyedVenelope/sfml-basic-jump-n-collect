#pragma once
#include <SFML\Graphics.hpp>

class ScoreText {
public:
	ScoreText(sf::Vector2f position);

	sf::Text getText();

	void setText(std::string text);

private:
	sf::Font m_font;
	sf::Text m_text;
	std::string m_string;
};
