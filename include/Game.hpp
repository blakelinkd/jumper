#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <cmath>
#include "Wall.hpp"
#include "Player.hpp"
#include "HUD.hpp"
#include "Grid.hpp"
#include "Missile.hpp"



class Game {

public:
	
	Game();
	void run();
	Wall mTop;
	HUD hud;
	Player player;
	Player planet_earth;
	Missile missile;
	Grid grid;
	float angleBetween(sf::Vector2f a, sf::Vector2f b);
	float dot(sf::Vector2f v1, sf::Vector2f v2);
	

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
	bool mIsMissileLaunched = false;
	int clickX;
	int clickY;
	float dx;
	float dy;
	float length;
	float angle;
	float deg;
	sf::Vector2f direction;

private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
	sf::CircleShape mPlayer2;



};