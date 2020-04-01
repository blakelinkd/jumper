#include "Grid.hpp"
#include <iostream>

Grid::Grid()
{
    unsigned int width = 1024;
    unsigned int height = 768;
    int space = 16; // space between lines
    imageBuffer.create(width, height, sf::Color::Transparent);

    for (double i = 0; i < imageBuffer.getSize().x * imageBuffer.getSize().y; i++) {
		unsigned int x = (int)i % width;
		unsigned int y = floor(i / width);
		//if ((int)i % space == 0) {
		//	imageBuffer.setPixel(x, y, sf::Color::Red);
		//}
        if( y % space == 0) {
            imageBuffer.setPixel(x, y, sf::Color::Green);
        }
        if( x % space == 0) {
            imageBuffer.setPixel(x, y, sf::Color::Blue);
        }
        
        
	}
    

	if (! texture.loadFromImage(imageBuffer, sf::IntRect(0, 0, width, height))) {
		std::cerr << "Cannot load texture from image buffer. " << std::endl;
	}
    
    this->setTexture(texture);
	
}

sf::Texture Grid::getTexture() {
    return texture;
}