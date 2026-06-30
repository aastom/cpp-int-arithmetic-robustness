#ifndef INPUT_UTILS_HPP
#define INPUT_UTILS_HPP

#include <string>

/**
 * @brief Prompts the user for an integer input and robustly handles invalid entries.
 * 
 * This function repeatedly prompts the user until a valid integer is entered.
 * It handles non-numeric input, ensures the input fits within an `int` type,
 * clears `std::cin` error flags, and ignores remaining invalid input in the buffer.
 * 
 * @param prompt The message displayed to the user to request input.
 * @return The valid integer entered by the user.
 */
int getIntInput(const std::string& prompt);

#endif // INPUT_UTILS_HPP
