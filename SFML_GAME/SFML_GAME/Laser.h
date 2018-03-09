#include <SFML/Graphics.hpp>

class Laser
{
public:

	Laser(sf::Texture*, int);
	void UpdateLaser();
	bool laserm = true;
	void Draw(sf::RenderWindow& windows);
	sf::Vector2f position;
	~Laser();

private:
	sf::RectangleShape laser;
};

