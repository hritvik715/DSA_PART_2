// class Solution {
// public:
//     bool isNumber(string s) {
        
//     }
// };


#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int n = s.length();

        // Skip leading whitespaces
        while (i < n && isspace(s[i])) {
            i++;
        }

        // Optional sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            i++;
        }

        bool is_numeric = false;
        bool has_dot = false;
        bool has_exponent = false;

        // Check for digits and dot
        while (i < n && (isdigit(s[i]) || s[i] == '.')) {
            if (isdigit(s[i])) {
                is_numeric = true;
            } else if (s[i] == '.') {
                if (has_dot) {
                    return false; // More than one dot
                }
                has_dot = true;
            }
            i++;
        }

        // Check for exponent
        if (i < n && (s[i] == 'e' || s[i] == 'E')) {
            if (!is_numeric) {
                return false; // No digits before exponent
            }
            has_exponent = true;
            i++;

            // Optional sign after exponent
            if (i < n && (s[i] == '+' || s[i] == '-')) {
                i++;
            }

            is_numeric = false; // Reset is_numeric for digits after exponent
            while (i < n && isdigit(s[i])) {
                is_numeric = true;
                i++;
            }

            if (!is_numeric) {
                return false; // No digits after exponent
            }
        }

        // Skip trailing whitespaces
        while (i < n && isspace(s[i])) {
            i++;
        }

        return is_numeric && i == n;
    }
};

/*
1. Code: A clean, optimized implementation in cpp
2. Your Thoughts:
The problem requires validating if a given string represents a valid number according to a specific set of rules. The approach involves iterating through the string and checking for different components of a number, such as digits, signs, a decimal point, and an exponent.  Several boolean flags are used to track the presence of these components and ensure that they appear in the correct order and frequency. The code handles edge cases such as multiple decimal points, missing digits before or after the exponent, and leading/trailing whitespaces.

3. Time complexity: O(X) where X is the length of the input string s. The algorithm iterates through the string at most once to validate the number. Therefore, the time complexity is directly proportional to the length of the input string.

4. Space complexity: O(1). The algorithm uses a fixed number of boolean variables and integer indices, regardless of the input string's size. Therefore, the space required by the algorithm remains constant, making the space complexity O(1).
*/