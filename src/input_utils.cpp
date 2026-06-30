#include "input_utils.hpp"
#include <iostream>
#include <limits>

int getIntInput(const std::string& prompt) {
    int value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;

        if (std::cin.fail()) {
            // Input failed (e.g., non-numeric input, or input too large/small for int)
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear(); // Clear the error flags
            // Ignore the rest of the invalid line
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Input was successful, but check if there's extraneous input on the line
            // If the next character is not a newline, there's extra input
            char nextChar = std::cin.peek(); // Peek at the next character without extracting
            if (nextChar != '\n' && nextChar != EOF) {
                std::cout << "Invalid input. Please enter only an integer.\n";
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the rest of the line
                continue; // Re-prompt
            }
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Consume the rest of the line (the newline character)
            break; // Valid input received, exit loop
        }
    }
    return value;
}
