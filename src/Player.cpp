#include "Player.hpp"
#include <iostream>

Player::Player(std::string texture_path) {
	std:: cout << "Player(" << texture_path << ") constructor " << std::endl;
	texture.loadFromFile(texture_path);
	this->setOrigin(floor(texture.getSize().x / 2), floor(texture.getSize().y / 2));
	this->setTexture(texture); 
	this->setPosition(100, 100);
}
Player::Player() {
	std::cout << "Player() default constructor" << std::endl;
	texture.loadFromFile("assets/ship.png");
	this->setOrigin(floor(texture.getSize().x / 2), floor(texture.getSize().y / 2));
	this->setTexture(texture); 
	this->setPosition(600, 400);

}
Player::Player(int width, int height) 
{
	
	

}

void Player::pulsate(sf::Color color, sf::Time deltaTime) {
	for (double i = 0; i < background.getSize().x * background.getSize().y; i++) {
		unsigned int x = (int)i % this->background.getSize().x;
		unsigned int y = floor(i / this->background.getSize().x);
		
		sf::Color mcolor = background.getPixel(x, y);
		
		mcolor.r += 0.006 * color.r;
		
		background.setPixel(x, y, mcolor);
		
	}
	this->texture.update(background);
}

void Player::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;
}

void Player::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
			case sf::Event::KeyPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(event.key.code, false);
				break;
			case sf::Event::Closed:
				mWindow.close();
				break;
		}
		
	}
}

void Player::update() {


}
void Player::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (mIsMovingUp)
		movement.y -= 1.f;
	if (mIsMovingDown)
		movement.y += 1.f;
	if (mIsMovingLeft)
		movement.x -= 1.f;
	if (mIsMovingRight)
		movement.x += 1.f;
	
	this->move(movement);

	

}
void Player::render() {
	
}
