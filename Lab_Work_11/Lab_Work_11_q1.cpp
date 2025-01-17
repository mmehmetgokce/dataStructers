#include <iostream>
#include <unordered_set>
#include <string>
#include <cctype>

int main() {
    std::string userInput;
    std::unordered_set<char> uniqueLetters;

    std::cout << "Enter text: ";
    std::getline(std::cin, userInput);

    for (char character : userInput) {
        if (std::isalpha(static_cast<unsigned char>(character))) {
            uniqueLetters.insert(character);
        }
    }

    std::cout << "Unique letters in text: ";
    for (char letter : uniqueLetters) {
        std::cout << letter << ' ';
    }
    std::cout << std::endl;

    return 0;
}