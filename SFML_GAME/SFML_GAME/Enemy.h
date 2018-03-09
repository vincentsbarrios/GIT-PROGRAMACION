#include <SFML/Graphics.hpp>


class Enemy
{
public:
	Enemy(sf::Texture*,float,float,float speed);
	~Enemy();
	int cont;

	void Draw(sf::RenderWindow& windows);
	void Update();
	
private:
	sf::RectangleShape body;
	float speed;
};

