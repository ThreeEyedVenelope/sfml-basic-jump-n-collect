#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ground.h"
#include "Player.h"
#include "Coin.h"
#include "ScoreText.h"

sf::Vector2f windowSize(800, 800);
sf::VideoMode vm(windowSize.x, windowSize.y);
sf::RenderWindow window(vm, "Basic Jump N Collect");

sf::Texture backgroundTexture;
sf::Sprite backgroundSprite;

Ground ground(windowSize);
Player player(ground);

std::vector<Coin*> coins;
Coin coin1({ 120,525 });
Coin coin2({ 475,500 });
Coin coin3({ 620, 475 });

ScoreText scoreText({ 20,10 });
int score = 0;
std::string scoreString = "Score: " + std::to_string(score);

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
    coins.push_back(&coin3);
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

void checkCoinCollision() {
    for (int i = 0; i < coins.size(); i++) {
        if (player.collidingWithCoin(coins[i])) {
            coins[i]->position({ 900,900 });
            score++;
            scoreString = "Score: " + std::to_string(score);
            std::cout << "Score: " + std::to_string(score);
            scoreText.setText(scoreString);
        }
    }

}

void drawCoins() {
    for (int i = 0; i < coins.size(); i++) {
        window.draw(coins[i]->getSprite());
    }
}

int main()
{
    setBackground();
    setCoins();
    scoreText.setText(scoreString);
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

        checkCoinCollision();

        sf::Time t = clock.restart();
        player.update(t, windowSize, groundHeight, gravity);

        window.clear();
        window.draw(backgroundSprite);
        window.draw(ground.getSprite());
        drawCoins();
        window.draw(player.getSprite());
        window.draw(scoreText.getText());
        window.display();
    }
    return 0;
}
