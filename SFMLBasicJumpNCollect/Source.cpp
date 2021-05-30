#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ground.h"
#include "Player.h"

sf::Vector2f windowSize(800, 800);
sf::VideoMode vm(windowSize.x, windowSize.y);
sf::RenderWindow window(vm, "Basic Jump N Collect");

sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

Ground ground(windowSize);
Player player(ground);

void setBackground() {
    backgroundTexture.loadFromFile("graphics/OrangeBackgroundx8.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
}

int main()
{
    setBackground();

    while (window.isOpen()) {
        sf::Event event; 
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.clear();
        window.draw(backgroundSprite);
        window.draw(ground.getSprite());
        window.draw(player.getSprite());
        window.display();
    }
    return 0;
}
