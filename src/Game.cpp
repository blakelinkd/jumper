#include "Game.hpp"
#include <iostream>

Game::Game() 
: mWindow(sf::VideoMode(1024, 768), "Jumper!"), mPlayer(), mTop(0, 0)
{

	//Wall top(800, 600);
	rads = 0;
	mPlayer.setRadius(40.f);
	mPlayer.setPosition(100.f, 100.f);
	mPlayer.setFillColor(sf::Color::Cyan);
	mPlayer2.setRadius(4.f);
	mPlayer2.setPosition(200.f, 200.f);
	mPlayer2.setFillColor(sf::Color::Magenta);
	
}
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.f / 60.f);

  while(mWindow.isOpen()) 
  {

	  processEvents();
	  timeSinceLastUpdate += clock.restart();
	  while (timeSinceLastUpdate > TimePerFrame)
	  {
		  timeSinceLastUpdate -= TimePerFrame;
		  processEvents();
		  update(TimePerFrame);
	  }
	  render();
  }

  
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
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

void Game::processEvents()
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

void Game::update(sf::Time deltaTime)
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
	
	mPlayer.move(movement);

	sf::Vector2f bounce(0.f, 1.f);
	

	bounce.y *= 0.4 * sin(M_PI_2);
	bounce.x *= 0.4 * sin(M_PI_2);
	rads += deltaTime.asSeconds()/60;
	if (rads >360)
		rads = 0;
	
	mPlayer2.move(bounce);

}
void Game::render() {
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.draw(mPlayer2);
	// walls
	mWindow.draw(mTop);
	mWindow.display();
}
