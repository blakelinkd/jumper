#include <SFML/Graphics.hpp>
#include <cmath>


class Game {

public:
	
	Game();
	void run();

private:
	void processEvents();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void update(sf::Time deltaTime);
	void render();
	double rads;
	bool mIsMovingUp = false;
	bool mIsMovingDown = false;
	bool mIsMovingLeft = false;
	bool mIsMovingRight = false;

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	sf::CircleShape mPlayer2;



};