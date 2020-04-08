#include "Game.hpp"
#include <iostream>

Game::Game() 
: mWindow(sf::VideoMode(1024, 768), "Jumper!"), mTop(1024, 15), planet_earth("assets/planet-earth.png"), hud(),
grid(), missile()
{

	//Wall top(800, 600);
	rads = 0;
	int clickX = 0;
	int clickY = 0;
	direction.y = 1;
	direction.x = 1;
	sf::Vector2f direction = sf::Vector2f(0,0);
	
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

float Game::dot(sf::Vector2f v1, sf::Vector2f v2)
{
  return v1.x * v2.x + v1.y * v2.y;
}
//b is considered the base
float Game::angleBetween(sf::Vector2f a, sf::Vector2f b) {
    sf::Vector2f p(-b.y, b.x);
    float b_coord = dot(a, b);
    float p_coord = dot(a, p);
    return atan2f(p_coord, b_coord);
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
	if (mIsMissileLaunched) {
		missile.setTarget(sf::Mouse::getPosition());
		std::cout << "fart" << std::endl;
	}
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		clickX = sf::Mouse::getPosition(mWindow).x;
		clickY = sf::Mouse::getPosition(mWindow).y;
		
		if(clickX < missile.getPosition().x) {
			direction.x *= -1;
		}
		if(clickY < missile.getPosition().y) {
			direction.y *= -1;
		}

		clickX = clickX - missile.getPosition().x;
		clickY = clickY - missile.getPosition().y;

		dx = clickX / sqrt(clickX*clickX + clickY * clickY);
		dy = clickY / sqrt(clickX * clickX + clickY * clickY);
		length = sqrt(clickX*clickX + clickY + clickY);

		missile.move(
		sf::Vector2f(dx, dy)
		);

		/* clickX = sf::Mouse::getPosition(mWindow).x;
		clickY = sf::Mouse::getPosition(mWindow).y;
		dx = clickX - missile.getPosition().x;
		dy = clickY - missile.getPosition().y; */

		//std::cout << missile.getRotation() << " degrees." << std::endl;
		clickX = sf::Mouse::getPosition(mWindow).x;
		clickY = sf::Mouse::getPosition(mWindow).y;
	
		//length = sqrt(abs((missile.getPosition().x - clickX) * (missile.getPosition().x - clickX)) + abs((missile.getPosition().y - clickY) *  (missile.getPosition().y - clickY)));
		length = sqrt(( (missile.getPosition().x - clickX) * (missile.getPosition().x - clickX)) + ((missile.getPosition().y - clickY) *  (missile.getPosition().y - clickY)));
		
		//angle =  ( atan(length / abs(clickY - missile.getPosition().y))) * (180/M_PI);
		//length = 1;
		/* angle = atan( 
			( abs(clickY - missile.getPosition().y) / length) / 
			( abs(clickX - missile.getPosition().x) / length)
		 ) * 360;// * (180/M_PI); */
		 /* angle = atan( 
			( abs(clickY - missile.getPosition().y) / length ) / 
			( abs(clickX - missile.getPosition().x) / length )
		 ) * (180/M_PI);// * 360;// * (180/M_PI); */
		
		//angle = atan2(clickY - missile.getPosition().y, clickX - missile.getPosition().x) * (180 / M_2_PI);
		//angle = remainder(angle, 360.);
		//angle = fabs(angle);

		angle = acos( (missile.getPosition().x - clickX) / length);
		//if(angle < 0) {
		//	angle = angle* -1;
		//}
		angle *= (180 / M_PI);
		angle = remainder(angle, 360.);
		//angle = fabs(angle);
		

	
		
		std::cout << length << " / " << abs(clickY - missile.getPosition().y) << std::endl;
		std::cout << "angle: " << angle  << " length: " << length << " dx: " << dx << " dy: " << dy << std::endl;
		std::cout << "clickX: " << clickX << " clickY: " << clickY << " missile_x: " << missile.getPosition().x <<
		" missile_y: " << missile.getPosition().y << std::endl;
		//missile.rotate(0.2 * (angle + 180));

		//missile.rotate(angle);
		//missile.setRotation(angle - 90);

		if(clickY < missile.getPosition().y) {
			missile.setRotation(angle - 90);
			std::cout << "poop: " << std::endl;
		} 
		else {
			missile.setRotation(-angle  -90);
			std::cout << "fart: " << std::endl;
		}


		


		

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
