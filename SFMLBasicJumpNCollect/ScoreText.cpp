#include "ScoreText.h"

ScoreText::ScoreText(sf::Vector2f position) {
	m_font.loadFromFile("fonts/CabinCondensed-Bold.ttf");
	m_text.setFont(m_font);
	m_text.setCharacterSize(50);
	m_text.setPosition(position);
}

sf::Text ScoreText::getText() {
	return m_text;
}

void ScoreText::setText(std::string text) {
	m_text.setString(text);
}