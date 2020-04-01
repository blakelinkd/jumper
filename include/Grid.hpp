#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <cmath>
class Grid : public sf::Sprite {


    public:
    Grid();
    sf::Texture getTexture();

    private:
    sf::Image imageBuffer;
    sf::Texture texture;


};