#include <iostream>
#include <fstream>

void mediaToBinary(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream media(inputFile, std::ios::binary);
    std::ofstream binary(outputFile, std::ios::binary);

    if (!media) {
        std::cerr << "Error opening media file: " << inputFile << std::endl;
        return;
    }
    if (!binary) {
        std::cerr << "Error creating binary file: " << outputFile << std::endl;
        return;
    }

    binary << media.rdbuf(); // Copy contents
    std::cout << "Media file converted to binary successfully: " << outputFile << std::endl;

    media.close();
    binary.close();
}

int main() {
    std::string mediaFile = "cat.jpg";   // Change this to your media file
    std::string binaryFile = "output.bin"; // Binary output file

    mediaToBinary(mediaFile, binaryFile);
    return 0;
}
