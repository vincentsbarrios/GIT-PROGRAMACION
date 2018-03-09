#include <SFML/Graphics.hpp>


class Player
{
public:
	Player(sf::Texture* texture, float speed);
	~Player();
	sf::Vector2f position;

	void Update(float deltaTime);
	void Draw(sf::RenderWindow& windows);
	void UpdateLaser2(float deltaTime);
	bool laserm = true;
private:
	sf::RectangleShape body;
	sf::RectangleShape laser;
	float speed;
};

