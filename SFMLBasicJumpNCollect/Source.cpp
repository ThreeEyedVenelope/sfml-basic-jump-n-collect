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
Coin coin1({ 120,525 });
Coin coin2({ 600,475 });

float groundHeight = ground.getSprite().getPosition().y - ground.getTexture().getSize().y / 2;
float gravity = 400.0f;
bool playerInAir = false; 
int jumpCount = 0; 
int maxJumpCount = 800;

void setBackground() {
    backgroundTexture.loadFromFile("graphics/OrangeBackgroundx8.png");
    backgroundSprite.setTexture(backgroundTexture);
    backgroundSprite.setPosition(0, 0);
}


void setCoins() {
    coins.push_back(&coin1);
    coins.push_back(&coin2);
}

void checkKeyPress() {

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        player.goRight();
        playerInAir = false;
    }
    else {
        player.stopRight();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        player.goLeft();
        playerInAir = false;
    }
    else {
        player.stopLeft();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (jumpCount < maxJumpCount && !playerInAir) {
            player.goJump(groundHeight);
            jumpCount++;
        }
        else if (jumpCount >= maxJumpCount) {
            if (player.collidingWithGround(ground)) {
                jumpCount = 0;
            }
            player.stopJump();
        }
        std::cout << "Jump Count: " << std::to_string(jumpCount);
    }
    else {
        player.stopJump();
    }

}

int main()
{
    setBackground();
    setCoins();
    sf::Clock clock;

    while (window.isOpen()) {
        sf::Event event; 
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyReleased) {
                if (jumpCount != 0) {
                    playerInAir = true;
                }
            }
        }
        
        checkKeyPress();

        if (player.collidingWithGround(ground)) {
            playerInAir = false;
            jumpCount = 0; // reset jump count when the player touches down on the floor 
        }

        sf::Time t = clock.restart();
        player.update(t, windowSize, groundHeight, gravity);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(ground.getSprite());
        window.draw(coin1.getSprite());
        window.draw(coin2.getSprite());
        window.draw(player.getSprite());
        window.display();
    }
    return 0;
}
