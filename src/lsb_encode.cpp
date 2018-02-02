// Least-Significant Bit Steganography - Encoding
// Matthew DiBello

#include <iostream>
#include <fstream>
#include <sstream>
#include <bitset>
#include <queue>
#include <SFML/Graphics.hpp>

std::queue<bool> stringToBinary(std::string message);

int main(int argc, char* argv[]) {

    std::string inputImageFilename;
    std::string inputMessageFilename;
    std::string outputImageFilename;

    if (argc == 4) {
        inputImageFilename   = argv[1];
        inputMessageFilename = argv[2];
        outputImageFilename  = argv[3];
    }
    else if (argv[1] == std::string("--help")) {
        std::cout << "Run this program with the format: ";
        std::cout << "./lsb_encode path/to/input.png path/to/msg.txt path/to/output.png";
        std::cout << std::endl;
        exit(1);
    }
    else {
        std::cout << "ERROR: Incorrect number of arguments." << std::endl;
        std::cout << "Run this program with the format: ";
        std::cout << "./lsb_encode path/to/input.png path/to/msg.txt path/to/output.png";
        std::cout << std::endl;
        exit(-1);
    }

    sf::Image referenceImage;
    if (!referenceImage.loadFromFile(inputImageFilename))
        return -1;

    sf::Vector2u referenceSize;
    referenceSize = referenceImage.getSize();

    std::ifstream stream(inputMessageFilename);
    std::stringstream messageBuffer;
    messageBuffer << stream.rdbuf();
    std::string message = messageBuffer.str();
    std::queue<bool> binaryMessage = stringToBinary(message);

    sf::Image newImage;
    newImage.create(referenceSize.x, referenceSize.y);
    sf::Color referencePixel;
    sf::Color newPixel;

    for (unsigned int y = 0; y < referenceSize.y; y++) {
        for (unsigned int x = 0; x < referenceSize.x; x++) {

            referencePixel = referenceImage.getPixel(x, y);

            if (!binaryMessage.empty()) {

                newPixel.r = (referencePixel.r & 254) | binaryMessage.front();
                binaryMessage.pop();
                newPixel.g = (referencePixel.g & 254) | binaryMessage.front();
                binaryMessage.pop();
                newPixel.b = (referencePixel.b & 254) | binaryMessage.front();
                binaryMessage.pop();
                newPixel.a = (referencePixel.a & 254) | binaryMessage.front();
                binaryMessage.pop();
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
        for (int i = 128; i > 0; i /= 2) {
            if (*it & i) {
                bits.push(1);
            }
            else {
                bits.push(0);
            }
        }
    }

    // put null character at end of message
    for (int i = 0; i < 8; i++) {
        bits.push(0);
    }

    return bits;
}
