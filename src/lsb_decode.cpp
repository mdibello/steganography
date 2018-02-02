// Least-Significant Bit Steganography - Decoding
// Matthew DiBello

#include <iostream>
#include <stack>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {

    std::string imageFilename;

    if (argc == 2) {
        imageFilename = argv[1];
    }
    else if (arg[1] == std::string("--help")) {
        std::cout << "Run this program with the format: ";
        std::cout << "./lsb_decode path/to/input.png" << std::endl;
        exit(1);
    }
    else {
        std::cout << "ERROR: Incorrect number of arguments." << std::endl;
        std::cout << "Run this program with the format: ";
        std::cout << "./lsb_decode path/to/input.png" << std::endl;
        exit(-1);
    }

    sf::Image image;
    if (!image.loadFromFile(imageFilename))
        return -1;

    sf::Vector2u imageSize;
    imageSize = image.getSize();

    char nextChar;
    std::stack<bool> bitBuffer;
    std::string message;
    sf::Color pixel;
    bool endOfMessage = false;

    for (unsigned int y = 0; y < imageSize.y && !endOfMessage; y++) {
        for (unsigned int x = 0; x < imageSize.x && !endOfMessage; x++) {

            pixel = image.getPixel(x, y);

            bitBuffer.push(pixel.r & 1);
            bitBuffer.push(pixel.g & 1);
            bitBuffer.push(pixel.b & 1);
            bitBuffer.push(pixel.a & 1);

            if (bitBuffer.size() == 8) {

                nextChar = 0;

                for (unsigned int i = 1; i < 255; i *= 2) {
                    nextChar += (i * bitBuffer.top());
                    bitBuffer.pop();
                }

                if (nextChar == 0)
                    endOfMessage = true;

                message += nextChar;
            }
        }
    }

    std::cout << message << std::endl;

    return 0;
}
