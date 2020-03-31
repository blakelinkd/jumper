#include "Wall.hpp"
#include <iostream>


Wall::Wall() {

}
Wall::Wall(int width, int height) 
{
	background.create(32, 32, sf::Color::Green);

	

	
	for (double i = 0; i <= background.getSize().x * background.getSize().y; i++) {
		int x = (int)i % 32;
		int y = floor(i / 32);
		std::cout << "i = " << i << ", i % 32 = " << (int)i % 32 << ", floor(i / 32) = " << floor(i / 32) << std::endl;
		if ((int)i % 2 == 0) {
			background.setPixel(x, y, sf::Color::Red);
		}
		// std::cout << background.getPixel((int)i % 32, floor(i / 32)).toInteger() << " " << std::endl;
	}
	std::cout << "first pixel: " << background.getPixel(0, 0).toInteger() << "last pixel: " << background.getPixel(32, 32).toInteger() << std::endl;
	/* if (! this->texture.create(32, 32)) {
		std::cerr << "could not create texture." << std::endl;
	} */
	if (! texture.loadFromImage(background, sf::IntRect(0, 0, 32, 32))) {
		std::cerr << "Cannot load image. " << std::endl;
	}
	//texture.update(background);
	
	this->setTexture(texture);
	this->scale(16.f, 16.f);

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
