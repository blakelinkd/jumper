#include <SFML/Graphics.hpp>
#include <cmath>


class Wall : public sf::Sprite {

public:
	Wall();
	Wall(int width, int height);

private:
	void processEvents();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update();
	void update(sf::Time deltaTime);
	void render();
	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;
	sf::Texture texture;
	sf::Image background;

private:
	sf::RenderWindow mWindow;



};