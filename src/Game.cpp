#include "Game.hpp"
#include <iostream>

Game::Game() 
: mWindow(sf::VideoMode(1024, 768), "Jumper!"), mTop(1024, 15), planet_earth("assets/planet-earth.png"), hud(),
grid(), missile()
{

	//Wall top(800, 600);
	rads = 0;
	
	mPlayer2.setRadius(4.f);
	missile.setPosition(1024/2, 768/2);
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
	else if (key == sf::Mouse::Left)
		mIsMissileLaunched = isPressed;
		
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
			case sf::Event::MouseButtonPressed:
				handlePlayerInput(event.key.code, true);
				break;
			case sf::Event::MouseButtonReleased:
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
		player.rotate(-5.0f); // movement.x -= 1.f;
	if (mIsMovingRight)
		player.rotate(5.0f); // movement.x += 1.f;
	if (mIsMissileLaunched) {
		missile.setTarget(sf::Mouse::getPosition());
		std::cout << "fart" << std::endl;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		missile.setTarget(sf::Mouse::getPosition());
		missile.move(sf::Vector2f(-0.001 * planet_earth.getPosition().x, -0.001 * planet_earth.getPosition().y));
	}
	player.move(movement);

	sf::Vector2f bounce(0.f, 1.f);
	

	bounce.y *= 0.4 * sin(M_PI_2);
	bounce.x *= 0.4 * sin(M_PI_2);
	rads += deltaTime.asSeconds()/60;
	if (rads >360)
		rads = 0;
	
	mPlayer2.move(bounce);
	mTop.pulsate(sf::Color::Red, deltaTime);

}
void Game::render() {
	mWindow.clear();
	mWindow.draw(grid);
	mWindow.draw(mPlayer);
	mWindow.draw(mPlayer2);
	// walls
	mWindow.draw(mTop);
	mWindow.draw(planet_earth);
	mWindow.draw(player);
	mWindow.draw(missile);
	mWindow.draw(hud.getText());
	mWindow.display();
}
