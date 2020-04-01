#include <SFML/Graphics.hpp>
#include <cmath>


class Player : public sf::Sprite {

public:
	Player();
	Player(std::string texture_path);
	Player(int width, int height);
	void pulsate(sf::Color, sf::Time deltaTime);

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