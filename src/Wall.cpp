#include "Wall.hpp"
#include <iostream>


Wall::Wall() {

}
Wall::Wall(int width, int height) 
{
	background.create(width, height, sf::Color::Green);
	
	for (double i = 0; i < background.getSize().x * background.getSize().y; i++) {
		unsigned int x = (int)i % width;
		unsigned int y = floor(i / width);
		if ((int)i % 2 == 0) {
			background.setPixel(x, y, sf::Color::Red);
		}
	}

	if (! texture.loadFromImage(background, sf::IntRect(0, 0, width, height))) {
		std::cerr << "Cannot load image. " << std::endl;
	}
	this->setTexture(texture);

}

void Wall::pulsate(sf::Color color, sf::Time deltaTime) {
	for (double i = 0; i < background.getSize().x * background.getSize().y; i++) {
		unsigned int x = (int)i % this->background.getSize().x;
		unsigned int y = floor(i / this->background.getSize().x);
		
		sf::Color mcolor = background.getPixel(x, y);
		
		mcolor.r += 0.006 * color.r;
		
		background.setPixel(x, y, mcolor);
		
	}
	this->texture.update(background);
}

void Wall::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
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

void Wall::processEvents()
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

void Wall::update() {


}
void Wall::update(sf::Time deltaTime)
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
void Wall::render() {
	
}
