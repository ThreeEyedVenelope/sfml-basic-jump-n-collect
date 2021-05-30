#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ground.h"
#include "Player.h"
#include "Coin.h"

sf::Vector2f windowSize(800, 800);
sf::VideoMode vm(windowSize.x, windowSize.y);
sf::RenderWindow window(vm, "Basic Jump N Collect");

sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

Ground ground(windowSize);
Player player(ground);

std::vector<Coin*> coins;
Coin coin1({ 120,500 });
Coin coin2({ 600,400 });

void setBackground() {
    backgroundTexture.loadFromFile("graphics/OrangeBackgroundx8.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
}


void setCoins() {
    coins.push_back(&coin1);
    coins.push_back(&coin2);
}

int main()
{
    setBackground();
    setCoins();

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
        window.draw(coin1.getSprite());
        window.draw(coin2.getSprite());
        window.display();
    }
    return 0;
}
