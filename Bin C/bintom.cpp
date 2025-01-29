#include <iostream>
#include <fstream>

void binaryToMedia(const std::string& inputFile, const std::string& outputFile) {
    std::ifstream binary(inputFile, std::ios::binary);
    std::ofstream media(outputFile, std::ios::binary);

    if (!binary) {
        std::cerr << "Error opening binary file: " << inputFile << std::endl;
        return;
    }
    if (!media) {
        std::cerr << "Error creating media file: " << outputFile << std::endl;
        return;
    }

    media << binary.rdbuf(); // Copy binary data to media file
    std::cout << "Binary file converted back to media successfully: " << outputFile << std::endl;

    binary.close();
    media.close();
}

int main() {
    std::string binaryFile = "output.bin"; // The binary file
    std::string mediaFile = "cutie.jpg"; // The restored media file

    binaryToMedia(binaryFile, mediaFile);
    return 0;
}
