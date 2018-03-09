#include "Player.h"
#include <iostream>
using namespace std;


Player::Player(sf::Texture* texture, float speed)
{
	this->speed = speed;

	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(-400, -780);
	body.setTexture(texture);

	laser.setSize(sf::Vector2f(100.0f, 100.0f));
	laser.setOrigin(-400,-780);


}


Player::~Player()
{
}

void Player::Update(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	position = body.getPosition();
	
	if (position.x <= 380) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			movement.x += speed * deltaTime;
	}
	if (position.x >= -380) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			movement.x -= speed * deltaTime;
	}
	//std::cout << "POS: " << position.x << std::endl;

	body.move(movement);
}


void Player::Draw(sf::RenderWindow& windows)
{
	windows.draw(body);


}

void Player::UpdateLaser2(float deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	position = body.getPosition();
	if (laserm == true) {
		movement.y -= 0.5f;
	}
	if (position.y <= -900) {
		laserm = false;
	}
	

	body.move(movement);
	laser.move(movement);

}



