#include "HUD.hpp"
#include <iostream>

HUD::HUD() : font(), text() {

    if (!font.loadFromFile("assets/UbuntuMono-B.ttf")) {
        std::cerr << "could not load font: UbuntuMono-B.ttf" << std::endl;
    }
    text.setFont(font);
    text.setString("Hello, welcome to the HUD!");
    text.setCharacterSize(32);
    text.setPosition(sf::Vector2f(1024/2, 768/8));
    text.setFillColor(sf::Color::Red);
    sf::Image bufferImage;
    bufferImage.create(1024, 100);


}

sf::Text HUD::getText() {
    return text;
}