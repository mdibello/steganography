// Least-Significant Bit Steganography - Decoding
// Matthew DiBello

#include <iostream>
#include <bitset>
#include <stack>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

int main(int argc, char* argv[]) {

    std::string imageFilename = "../out/out.jpg";

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

                message += nextChar;
                
            }
        }
    }

    std::cout << message << std::endl;

    return 0;
}
