#include "Missile.hpp"
#include <iostream>


Missile::Missile() {

    texture.loadFromFile("assets/missile.png");
    this->setTexture(texture);
    //this->setOrigin(sf::Vector2f(this->texture.getSize().x/2, 0));
    
}

void Missile::setTarget(sf::Vector2i target) {
    this->mtarget = target;
    std::cout << "missile target set to: " << target.x << " - " << target.y << std::endl;

}

sf::Vector2i Missile::getTarget() {
    return this->mtarget;
}