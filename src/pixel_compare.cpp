// Pixel-by-Pixel Image Comparision
// Matthew DiBello

#include <iostream>
#include <string>
#include <stack>
#include <SFML/Graphics.hpp>

std::string pixelToBinaryString(sf::Uint32 pixel);

int main(int argc, char* argv[]) {

    std::string imageFilenameOne;
    std::string imageFilenameTwo;

    if (argc == 3) {
        imageFilenameOne = argv[1];
        imageFilenameTwo = argv[2];
    }
    else {
        if (argv[1] != std::string("--help")) {
            std::cout << "ERROR: Incorrect number of arguments." << std::endl;
        }
        std::cout << "Run this program with the format: ";
        std::cout << "./compare path/to/img1.png path/to/img2.png";
        std::cout << std::endl;
        exit(0);
    }

    sf::Image imageOne;
    if (!imageOne.loadFromFile(imageFilenameOne))
        return -1;
    sf::Image imageTwo;
    if (!imageTwo.loadFromFile(imageFilenameTwo))
        return -1;

    sf::Vector2u imageOneSize;
    imageOneSize = imageOne.getSize();
    sf::Vector2u imageTwoSize;
    imageTwoSize = imageTwo.getSize();

    if (imageOneSize.x != imageTwoSize.x || imageOneSize.y != imageTwoSize.y) {
        std::cout << "ERROR: Images are not the same dimension" << std::endl;
        exit(1);
    }

    sf::Color pixelOne;
    sf::Color pixelTwo;

    for (unsigned int y = 0; y < imageOneSize.y; y++) {
        for (unsigned int x = 0; x < imageOneSize.x; x++) {

            pixelOne = imageOne.getPixel(x, y);
            pixelTwo = imageTwo.getPixel(x, y);

            std::cout << "(" << x << ", " << y << ")" << std::endl;
            std::cout << pixelToBinaryString(pixelOne.toInteger()) << std::endl;
            std::cout << pixelToBinaryString(pixelTwo.toInteger()) << std::endl;
            std::cout << std::endl;
        }
    }

    return 0;
}

std::string pixelToBinaryString(sf::Uint32 pixel) {

    std::stack<bool> binarySequence;
    std::string binaryString;

    for (unsigned int i = 0; i < 4; i++) {
        for (unsigned int j = 0; j < 8; j++) {
            binarySequence.push(pixel & 1);
            pixel >>= 1;
        }
    }

    while (binarySequence.size() > 0) {
        for (unsigned int i = 0; i < 8; i++) {
            if (binarySequence.top())
                binaryString.push_back('1');
            else
                binaryString.push_back('0');
            binarySequence.pop();
        }
        binaryString.push_back(' ');
    }

    return binaryString;
}
