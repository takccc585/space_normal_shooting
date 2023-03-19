#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
#include <list>
#include "laser.h"

class Player {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float angle;
	float speedx, speedy;
	std::list<Laser*>lasers;
	sf::Clock timer;
public:
	Player() {
		texture.loadFromFile(PLAYER_FILE_NAME);
		sprite.setTexture(texture);
		sf::FloatRect bounds = sprite.getLocalBounds();
		sprite.setOrigin(bounds.width / 2, bounds.height / 2);
		sprite.setPosition(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2);
		timer.restart();
	}
	void update() {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
			angle -= 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
			angle += 3;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
			speed -= 0.3;
			if (speed <= 0) {
				speed = 0;
			}

		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
			speed += 1;
			if (speed >= 10) {
				speed = 10;
			}
		}
		speedx = speed * sin(angle * 3.1415 / 180);
		speedy = -speed * cos(angle * 3.1415 / 180);
		sprite.setRotation(angle);
		if ((speedx < 0 and sprite.getPosition().x >= 50.f) or (speedx > 0 and sprite.getPosition().x <= WINDOW_WIDTH - 50.f)) {
			sprite.move(speedx, 0);
		}
		if ((speedy < 0 and sprite.getPosition().y >= 50.f) or (speedy > 0 and sprite.getPosition().y <= WINDOW_HEIGHT - 50.f)) {
			sprite.move(0, speedy);
		}
		fire();
		for (auto laser : lasers) {
			laser->update();
		}
	}
	void fire() {
		int now = timer.getElapsedTime().asMilliseconds();
		if (now > FIRE_COOLDOWN) {
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
			{
				auto laser = new Laser(sprite.getPosition(), angle);
				lasers.push_back(laser);
				timer.restart();
			}
		}
	}
	void draw(sf::RenderWindow& window) {
		window.draw(sprite);
		for (auto laser : lasers) {
			window.draw(laser->getSprite());
		}
	}
};