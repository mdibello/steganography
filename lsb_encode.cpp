#include <iostream>
#include <bitset>
#include <queue>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

std::queue<bool> stringToBinary(std::string message);

int main(int argc, char* argv[]) {

    std::string inputImageFilename  = "pupper.jpg";
    std::string outputImageFilename = "out.jpg";

    sf::Image referenceImage;
    if (!referenceImage.loadFromFile(inputImageFilename))
        return -1;

    sf::Vector2u referenceSize;
    referenceSize = referenceImage.getSize();

    std::string message = "This is a secret message";
    std::queue<bool> binaryMessage = stringToBinary(message);

    sf::Image newImage;
    newImage.create(referenceSize.x, referenceSize.y);
    sf::Color referencePixel;
    sf::Color newPixel;
    unsigned char zeroMask = 254;
    unsigned char oneMask  = 255;

    for (unsigned int y = 0; y < referenceSize.y; y++) {
        for (unsigned int x = 0; x < referenceSize.x; x++) {

            referencePixel = referenceImage.getPixel(x, y);

            if (!binaryMessage.empty()) {

                newPixel.r = referencePixel.r & binaryMessage.front();
                binaryMessage.pop();
                newPixel.g = referencePixel.g & binaryMessage.front();
                binaryMessage.pop();
                newPixel.b = referencePixel.b & binaryMessage.front();
                binaryMessage.pop();
                newPixel.a = referencePixel.a & binaryMessage.front();
                binaryMessage.pop();

                //unsigned int pixelInt = referencePixel.toInteger();
                //std::bitset<32> pixelBits(pixelInt);
                //std::cout << pixelBits << std::endl;
                //unsigned int newPixelInt = newPixel.toInteger();
                //std::bitset<32> newPixelBits(newPixelInt);
                //std::cout << newPixelBits << std::endl << std::endl;
            }
            else {

                newPixel.r = referencePixel.r;
                newPixel.g = referencePixel.g;
                newPixel.b = referencePixel.b;
                newPixel.a = referencePixel.a;
            }

            newImage.setPixel(x, y, newPixel);
        }
    }

    newImage.saveToFile(outputImageFilename);

    return 0;
}

std::queue<bool> stringToBinary(std::string message) {

    std::queue<bool> bits;

    for (std::string::iterator it = message.begin(); it != message.end(); it++) {
        //std::cout << *it;
        for (int i = 128; i > 0; i /= 2) {
            if (*it & i) {
                bits.push(1);
                //std::cout << " 1 ";
            }
            else {
                bits.push(0);
                //std::cout << " 0 ";
            }
        }
        //std::cout << std::endl;
    }

    // put null character at end of message
    for (int i = 0; i < 4; i++) {
        bits.push(0);
    }

    return bits;
}
