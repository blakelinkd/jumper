#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Text.hpp>
class HUD : public sf::Sprite {

    public:
        HUD();
        sf::Text getText();

    
    private:
        sf::Font font;
        sf::Text text;


};