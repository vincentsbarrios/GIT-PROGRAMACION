#include "Enemy.h"
#include <iostream>


bool derecha = true;
bool izquierda = false;

Enemy::Enemy(sf::Texture* texture,float x ,float y,float speed)
{
	this->speed = speed;

	//setCaracteristicas del Objeto Enemy

	body.setSize(sf::Vector2f(100.0f, 100.0f));
	body.setOrigin(x,y);
	body.setTexture(texture);
	cont=0;
}

Enemy::~Enemy()
{
}

//Llama la funcion Draw de la clase Enemy.h

void Enemy::Draw(sf::RenderWindow & windows)
{
	windows.draw(body);
}

//WORKING.......

//Actualiza el Movimiento del Objeto Enemy
void Enemy::Update()
{
	
	sf::Vector2f movement(0.0f, 0.0f);
	sf::Vector2f position = body.getPosition();

	if (position.x < 76 && derecha == true) {
		movement.x += speed;
	}
	if (position.x >= 76) {
		derecha = false;
		izquierda = true;
		cont++;
	}
	if (position.x <= -76) {
		derecha = true;
		izquierda = false;
	}
	if (position.x > -76 && izquierda == true) {
		movement.x -= speed;

	}
	if (cont == 8) {
		movement.y += 20;
		cont = 0;
	}

	//std::cout << "COUNT: " << cont << std::endl;
	body.move(movement);

}

sf::RectangleShape Enemy::getBody()
{
	return body;
}
