#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Missile : public sf::Sprite {


    public:
    Missile();
    void setTarget(sf::Vector2i);
    sf::Vector2i getTarget();

    private:
    sf::Texture texture;
    sf::Vector2i mtarget;

};