#include <iostream>
#include <fstream>
#include <string>
#include <vector> // Using std::vector is generally preferred for dynamic arrays,
                // but let's illustrate with raw pointers for this example.

int main() {
    std::ifstream inputFile("my_text_file.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error opening file!" << std::endl;
        return 1;
    }

    std::string line;
    int lineCount = 0;

    // First, count the number of lines in the file
    while (std::getline(inputFile, line)) {
        lineCount++;
    }

    // Close and reopen the file to read from the beginning
    inputFile.close();
    inputFile.open("my_text_file.txt");
    if (!inputFile.is_open()) {
        std::cerr << "Error reopening file!" << std::endl;
        return 1;
    }

    // Dynamically allocate an array of strings to store the lines
    std::string* lines = new std::string[lineCount];

    // Read the lines from the file and store them in the array
    for (int i = 0; i < lineCount; ++i) {
        std::getline(inputFile, lines[i]);
    }

    // Print the lines
    std::cout << "Contents of the file:" << std::endl;
    for (int i = 0; i < lineCount; ++i) {
        std::cout << lines[i] << std::endl;
    }

    // Important: Free the dynamically allocated memory
    delete[] lines;
    lines = nullptr;
    inputFile.close();

    return 0;
}
