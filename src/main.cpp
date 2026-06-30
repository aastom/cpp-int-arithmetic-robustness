#include <iostream>
#include <limits>
#include <string>
#include "input_utils.hpp"

// WARNING: This approach to overflow detection relies on Undefined Behavior.
// See README for details on why this is problematic and how it's avoided in the robust version.
// For learning step 1, this would be: (a + b < 0)

int main() {
    std::cout << "--- Integer Arithmetic Robustness Checker ---\n";

    // Step 2: Robust Input Validation (implemented via getIntInput function)
    int int1 = getIntInput("Enter the first integer: ");
    int int2 = getIntInput("Enter the second integer: ");

    long long mathematical_sum = (long long)int1 + int2; // Calculate true mathematical sum for comparison

    // Step 4: Refined Output Messaging and Conditional Logic Hierarchy
    // 1. If the first integer is negative.
    if (int1 < 0) {
        std::cout << "Condition met: The first integer is negative.\n";
    }
    // 2. If the second integer is negative (only if the first is not negative).
    else if (int2 < 0) {
        std::cout << "Condition met: The first integer is non-negative, but the second is negative.\n";
    }
    // 3. If the sum of the two integers is negative, assuming both inputs were non-negative
    //    (to detect potential integer overflow).
    else {
        // Both int1 and int2 are non-negative. Now check for overflow.
        // Step 3: Correct Integer Overflow Detection (avoiding UB)
        bool overflow_detected = false;
        if (int1 > std::numeric_limits<int>::max() - int2) {
            // Overflow will occur if we add int2 to int1
            overflow_detected = true;
        }

        if (overflow_detected) {
            std::cout << "Condition met: Potential integer overflow detected (both inputs positive).\n";
            std::cout << "Mathematical sum would exceed INT_MAX.\n";
        }
    }

    // Always print the sum of the two integers.
    // Note: If overflow occurred, the `int` sum will wrap around due to C++ rules for signed integers.
    // We print the `int` sum here to demonstrate this behavior.
    std::cout << "The computed sum of the two integers is: " << (int)(mathematical_sum) << "\n";
    // Optionally, print the mathematical sum if it was detectable and different
    if (mathematical_sum != (long long)(int1 + int2)) {
        std::cout << "(Note: The true mathematical sum was: " << mathematical_sum << ")\n";
    }

    return 0;
}
