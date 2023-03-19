#pragma once
#include <SFML/Graphics.hpp>
#include"settings.h"

class Laser {
private:
	sf::Sprite sprite;
	sf::Texture texture;
	float speed = LASER_SPEED, speedx, speedy;
public:
	Laser(sf::Vector2f playerPos, int playerAngle) {
		texture.loadFromFile(LASER_FILE_NAME);
		sprite.setTexture(texture);
		sprite.setPosition(playerPos);
		sprite.setRotation(playerAngle);
		speedx = speed * sin(playerAngle * 3.1415 / 180);
		speedy = -speed * cos(playerAngle * 3.1415 / 180);
	}
	void update() {
		sprite.move(speedx, speedy);
	}

	sf::Sprite& getSprite() { return sprite; }
	sf::Vector2f LaserGetPosition(const Laser& laser) {
		return sf::Vector2f{ laser.sprite.getGlobalBounds().left, laser.sprite.getGlobalBounds().top };
	}
};