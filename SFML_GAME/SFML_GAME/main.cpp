#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include <vector>


using namespace std;

vector <Player> bullets;


int main()
{
	
	sf::RenderWindow window(sf::VideoMode(900, 900), "SPACE INVADER (SUPER ALPHA VERSION)", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape rectangle(sf::Vector2f(900.0f, 900.0f));
	bool jugadorDisparo = false;
	sf::Texture texture;
	texture.loadFromFile("photo.jpg");
	rectangle.setTexture(&texture);

	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	soundBuffer.loadFromFile("uganda.ogg"); //theme song ->  "spaceinvader.ogg"
	sound.setBuffer(soundBuffer);

	//PLAYER SHIP
	sf::Texture playerTexture;
	playerTexture.loadFromFile("ship.png");
	Player player(&playerTexture, 0.5f);
	float deltaTime = 1.0f;

	sf::Texture laserTexture;
	laserTexture.loadFromFile("laser.png");
	Player laser(&laserTexture, 0.5f);
	

	//ENEMIES
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("enemy2.png");

	sf::Texture enemyTexture1;
	enemyTexture1.loadFromFile("enemy2.png");

	sf::Texture enemyTexture2;
	enemyTexture.loadFromFile("enemy2.png");

	sf::Texture enemyTexture3;
	enemyTexture1.loadFromFile("enemy2.png");

	Enemy enemy(&enemyTexture,-100,-10, 0.4f);
	Enemy enemy1(&enemyTexture1, -300, -10, 0.4f);
	Enemy enemy2(&enemyTexture, -500, -10, 0.4f);
	Enemy enemy3(&enemyTexture, -700, -10, 0.4f);


	
	//TIME
	sf::Clock clock;
	sf::Time time = sf::seconds(10);

	bool shoot = true;

	while (window.isOpen()) {
		sf::Event _event;
		while (window.pollEvent(_event))
		{
			switch (_event.type) {

			case sf::Event::Closed:
				window.close();
				break;

			case sf::Event::KeyPressed:
				if (_event.key.code == sf::Keyboard::U)
					sound.play();
				if (_event.key.code == sf::Keyboard::Escape)
					window.close();

				break;
			}
		}

		float right = 0;

		//KEYBOARDS INPUTS
		if (clock.getElapsedTime().asSeconds() >= time.asSeconds()) {
			clock.restart();
		}


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
			
			if (shoot == true) {
				bullets.push_back(Player(&laserTexture, 0.5f));
				shoot = false;
			}
		}
		else {

			shoot = true;
		}




		//sf::Time elapsed = clock.getElapsedTime();
		//std::cout << "TIME: " << elapsed.asSeconds() << std::endl;
		std::cout << "POS: " << player.position.x << std::endl;

		player.Update(deltaTime);
		laser.UpdateLaser2(deltaTime);

		enemy.Update();
		enemy1.Update();
		enemy2.Update();
		enemy3.Update();


		window.clear();

		window.draw(rectangle);
		enemy.Draw(window);

		enemy1.Draw(window);
		enemy2.Draw(window);
		enemy3.Draw(window);


		player.Draw(window);


		for (int i = 0; i < bullets.size(); i++) {


			bullets[i].UpdateLaser2(deltaTime);
			bullets[i].Draw(window);
		}


		laser.Draw(window);

		window.display();
	
	}


	return 0;
}