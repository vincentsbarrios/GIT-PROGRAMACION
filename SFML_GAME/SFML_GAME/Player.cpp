#include "Player.h"
#include <iostream>
using namespace std;

sf::Vector2f posLaser;

Player::Player(sf::Texture* texture, float speed)
{
	this->speed = speed;

	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(-400, -780);
	body.setTexture(texture);

	laser.setSize(sf::Vector2f(100.0f, 100.0f));

}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	position = body.getPosition();
	posLaser = position;
	
	if (position.x <= 380) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			movement.x += speed * deltaTime;
	}
	if (position.x >= -380) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			movement.x -= speed * deltaTime;
	}

	body.move(movement);
}


void Player::Draw(sf::RenderWindow& windows)
{
	windows.draw(body);
}

void Player::UpdateLaser()
{
	sf::Vector2f movement(0.0f, 0.0f);


	if (laserm == true) {
		movement.y -= 2.f;
	}
	if (position.y <= -900) {
		laserm = false;
	}
	
	std::cout << posLaser.x << std::endl;

	body.move(movement);


}



