#include <iostream>
#include <bitset>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {

    std::string inputImageFilename  = "pupper.jpg";
    std::string outputImageFilename = "out.jpg";

    sf::Image referenceImage;
    if (!referenceImage.loadFromFile(inputImageFilename))
        return -1;

    sf::Vector2u referenceSize;
    referenceSize = referenceImage.getSize();

    sf::Image newImage;
    sf::Color pixel;

    for (unsigned int y = 0; y < referenceSize.y; y++) {
        for (unsigned int x = 0; x < referenceSize.x; x++) {

            pixel = referenceImage.getPixel(x, y);
            uint32_t pixelInt = pixel.toInteger;
            std::bitset<32> pixelBits(pixelInt);
            std::cout << pixelBits << std::endl;

        }
    }

    return 0;
}
