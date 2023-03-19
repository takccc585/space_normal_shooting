#pragma once
#include <SFML/Graphics.hpp>
#include "settings.h"
class Meteor {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f speed;
public:
	enum MeteorSize { SMALL, AVERAGE, BIG };
	Meteor(std::string fileName, MeteorSize size, sf::Vector2f pos, sf::Vector2f fspeed) {
		texture.loadFromFile(fileName);
		sprite.setTexture(texture);
		if (size == BIG) {
			sprite.setScale(0.35f, 0.35f);
		}
		else if (size == AVERAGE) {
			sprite.setScale(0.20f, 0.20f);
		}
		else if (size == SMALL) {
			sprite.setScale(0.125f, 0.125f);
		}
		sprite.setPosition(pos);
		speed = fspeed;
	}
	void update() {
		sprite.move(speed);
		if ((sprite.getPosition().x<= LEFT_BORDER) or (sprite.getPosition().x >= RIGHT_BORDER)or (sprite.getPosition().y <= TOP_BORDER) or (sprite.getPosition().y >= RIGHT_BORDER)) {
			setRandomPosition();
		}
	}
	void setRandomPosition() {
		float x = rand() % 301 - 300.f;
		int choice = rand() % 10000;
		if (choice < 5000) x += 1500.f;
		float y= rand() % 301 - 300.f;
		choice = rand() % 10000;
		if (choice < 5000) y += 1200.f;
		float speedx = rand() % 9 - 4.f;
		float speedy = rand() % 9 - 4.f;
		sprite.setPosition(x, y);
	}
	sf::Sprite getSprite() { return sprite; }
};