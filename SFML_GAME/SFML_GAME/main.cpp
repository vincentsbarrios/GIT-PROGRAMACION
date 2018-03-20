#include <SFML/Graphics.hpp>
#include <math.h>
#include <cstdlib>
#include <iostream>
#include <SFML/Audio.hpp>
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "Laser.h"
#include <sstream>
#include "Menu.h"

using namespace std;

vector <Laser> bullets;
vector<Enemy> enemies;




void levelOne() {
	int LifePoints = 200, LifePoints1 = 200, LifePoints2 = 200, LifePoints3 = 200;

	//PROTOTYPE
	int player_points = 0;
	int level = 1;

	bool lf1 = true, lf2 = false, lf3 = false, lf4 = false;
	//Crea la ventana y el objeto
	sf::RenderWindow window(sf::VideoMode(1200, 900), "SPACE INVADER (SUPER ALPHA VERSION)", sf::Style::Close | sf::Style::Titlebar);

	sf::RectangleShape rectangle(sf::Vector2f(1200.0f, 900.0f));
	bool jugadorDisparo = false;
	sf::Texture texture;
	texture.loadFromFile("scene1.jpeg"); // backgroung GALAXY--> photo.jpg backgorundRetorx.png
	rectangle.setTexture(&texture);

	//PROTOTYPE TESTING... /////////////////////////////////////////////////////////////////////
	sf::Font font;
	if (!font.loadFromFile("af.ttf"))
	{
		//ERROR
	}

	sf::Text text_name;
	text_name.setFont(font);
	text_name.setString("PLAYERNAME");
	text_name.setFillColor(sf::Color::Cyan);
	text_name.setPosition(960, 600);
	text_name.setCharacterSize(25);



	//////////////////////////////////////////////////////////////////////////////////////////////

	//THEME SONG GAME
	sf::SoundBuffer soundBuffer;
	sf::Sound sound;
	soundBuffer.loadFromFile("spaceinvader.ogg"); //theme song ->  "spaceinvader.ogg"
	sound.setBuffer(soundBuffer);

	//SOUND EFFECT LASER
	sf::SoundBuffer soundBuffer2;
	sf::Sound sound2;
	soundBuffer2.loadFromFile("laser.wav");
	sound2.setBuffer(soundBuffer2);

	//PLAYER SHIP
	sf::Texture playerTexture;
	//Imagen del Ship
	playerTexture.loadFromFile("ship.png");
	Player player(&playerTexture, 0.5f);
	float deltaTime = 1.0f;


	sf::Texture laserTexture;
	//Imagen del Laser
	laserTexture.loadFromFile("laser.png");

	//ENEMIES
	sf::Texture enemyTexture;
	enemyTexture.loadFromFile("enemy3.png");

	sf::Texture enemyTexture1;
	enemyTexture1.loadFromFile("enemy.png");

	enemies.push_back(Enemy(&enemyTexture, -100, -10, 0.4f));
	enemies.push_back(Enemy(&enemyTexture, -300, -10, 0.4f));
	enemies.push_back(Enemy(&enemyTexture, -500, -10, 0.4f));
	enemies.push_back(Enemy(&enemyTexture, -700, -10, 0.4f));

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
				if (_event.key.code == sf::Keyboard::I)
					sound.pause();
				if (_event.key.code == sf::Keyboard::Escape)
					window.close();
				if (_event.key.code == sf::Keyboard::Space)
					sound2.play();
				break;
			}

		}


		float right = 0;

		//KEYBOARDS INPUTS
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {

			if (shoot == true) {
				bullets.push_back(Laser(&laserTexture, player.position.x + 400));
				shoot = false;
			}
		}
		else {
			shoot = true;
		}


		player.Update(deltaTime);

		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i].dead == false)
				enemies[i].Update();
		}



		window.clear();
		window.draw(rectangle);

		//DISPLAY POINTS
		stringstream  points_ss;
		points_ss << player_points;
		sf::Text text_points;
		text_points.setFont(font);
		text_points.setFillColor(sf::Color::Cyan);
		text_points.setCharacterSize(40);
		text_points.setString(points_ss.str().c_str());
		text_points.setPosition(1010, 240);

		stringstream  level_ss;
		level_ss << level;
		sf::Text text_level;
		text_level.setFont(font);
		text_level.setFillColor(sf::Color::Cyan);
		text_level.setCharacterSize(40);
		text_level.setString(level_ss.str().c_str());
		text_level.setPosition(1015, 400);

		//DISPLAY TEXT AND NUMBERS
		window.draw(text_name);
		window.draw(text_points);
		window.draw(text_level);


		for (int i = 0; i < enemies.size(); i++) {
			if (enemies[i].dead == false)
				enemies[i].Draw(window);
		}

		player.Draw(window);


		for (int i = 0; i < bullets.size(); i++) {
			bullets[i].UpdateLaser();
			bullets[i].Draw(window);

			for (int j = 0; j < enemies.size(); j++)
			{

				if (bullets[i].laser.getGlobalBounds().intersects(enemies[j].getBody().getGlobalBounds())) {

					if (lf1 == true) {
						LifePoints--;
						if (LifePoints == 9) {
							enemies[j].dead = true;
							lf2 = true;
							lf1 = false;
							player_points = player_points + 100;
						}
					}
					if (lf2 == true) {
						LifePoints1--;
						if (LifePoints1 == 9) {
							enemies[j].dead = true;
							lf3 = true;
							lf2 = false;
							player_points = player_points + 100;
						}
					}
					if (lf3 == true) {
						LifePoints2--;
						if (LifePoints2 == 9) {
							enemies[j].dead = true;
							lf4 = true;
							lf3 = false;
							player_points = player_points + 100;
						}
					}
					if (lf4 == true) {
						LifePoints3--;
						if (LifePoints3 == 9) {
							enemies[j].dead = true;
						}
					}

				}

			}
		}
		window.display();
	}
}

void controlMenu()
{
	sf::RenderWindow windowMain(sf::VideoMode(1200, 900), "MAIN MENU SPACE INVADER", sf::Style::Close | sf::Style::Titlebar);
	sf::RectangleShape image(sf::Vector2f(1200.0f, 900.0f));
	sf::Texture texture;
	texture.loadFromFile("control.jpeg");
	image.setTexture(&texture);

	while (windowMain.isOpen())
	{
		sf::Event evnt;

		while (windowMain.pollEvent(evnt))
		{
			if (evnt.type == evnt.Closed)
				windowMain.close();
		}
		windowMain.draw(image);
		windowMain.display();
	}
}

void mainMenu()
{
	sf::RenderWindow windowMain(sf::VideoMode(1200, 900), "MAIN MENU SPACE INVADER", sf::Style::Close | sf::Style::Titlebar);
	//sf::RectangleShape image(sf::Vector2f(1200.0f, 900.0f));

	//PROPOTYPE
	Menu menu(windowMain.getSize().x, windowMain.getSize().y);
	windowMain.setFramerateLimit(60);

	//sf::Texture texture;
	//texture.loadFromFile("mainMenu.jpg"); 
	//image.setTexture(&texture);

	while (windowMain.isOpen())
	{
		sf::Event evnt;
		while (windowMain.pollEvent(evnt))
		{
			switch (evnt.key.code)
			{
			case sf::Keyboard::Up:
				menu.MoveUp();
				break;

			case sf::Keyboard::Down:
				menu.MoveDown();
				break;

			case sf::Keyboard::Return:
				switch (menu.GetPressedItem())
				{
				case 0:
					cout << "PLAY" << endl;
					levelOne();
					break;
				case 1:
					cout << "CONTROLS" << endl;
					controlMenu();
					break;
				case 2:
					cout << "STATISTICS" << endl;
					break;
				}


			}

			if (evnt.type == evnt.Closed)
				windowMain.close();
		}

		menu.draw(windowMain);
		//windowMain.draw(image);
		windowMain.display();
	}

}


int main()
{


	mainMenu();
	
	

	return 0;
}

