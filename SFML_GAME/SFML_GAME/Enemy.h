#include <SFML/Graphics.hpp>


class Enemy
{
public:
	Enemy(sf::Texture*,float,float,float speed);
	~Enemy();
	int cont;
	bool dead = false;

	void Draw(sf::RenderWindow& windows);
	void Update();
	sf::RectangleShape getBody();
	
private:
	sf::RectangleShape body;
	float speed;
};

