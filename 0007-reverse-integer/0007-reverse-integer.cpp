#include <iostream>
#include <limits>

class Solution {
public:
    int reverse(int x) {
        int reversed = 0;

        while (x != 0) {
            int digit = x % 10;
            x /= 10;

            // Check for potential overflow before updating reversed
            if (reversed > std::numeric_limits<int>::max() / 10 || (reversed == std::numeric_limits<int>::max() / 10 && digit > 7)) {
                return 0;
            }
            if (reversed < std::numeric_limits<int>::min() / 10 || (reversed == std::numeric_limits<int>::min() / 10 && digit < -8)) {
                return 0;
            }

            reversed = reversed * 10 + digit;
        }

        return reversed;
    }
};
// 1. Code: A clean, optimized implementation in cpp

// 2. Your Thoughts: A list of key insights and reasoning behind your approach
// The core idea is to extract digits from the input integer `x` one by one, starting from the least significant digit, and construct the reversed integer.
// The most crucial part is to handle potential overflow. Before multiplying `reversed` by 10 and adding the new digit, we need to check if the result will exceed the maximum or minimum value that a 32-bit signed integer can hold.
// We use `std::numeric_limits<int>::max()` and `std::numeric_limits<int>::min()` to get the maximum and minimum possible integer values, respectively.
// The overflow check is done by comparing `reversed` with `std::numeric_limits<int>::max() / 10` and `std::numeric_limits<int>::min() / 10`.  We also need to check the last digit to handle cases where reversed is very close to the limit.

// 3. Time complexity: O(log10(|x|)) with a detailed explanation
// The time complexity is O(log10(|x|)) because the number of iterations in the `while` loop is proportional to the number of digits in the input integer `x`.  The number of digits in an integer `x` is approximately log10(|x|) + 1. Therefore, the loop runs a number of times proportional to the base-10 logarithm of the absolute value of x.

// 4. Space complexity: O(1) with a detailed explanation
// The space complexity is O(1) because we are only using a fixed number of integer variables (`reversed`, `digit`, and `x`). The amount of memory used does not depend on the size of the input integer `x`.  We are not using any additional data structures that scale with the input.