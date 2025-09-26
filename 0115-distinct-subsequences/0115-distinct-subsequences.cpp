#include <string>
#include <vector>

class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int m = s.length();
        int n = t.length();

        // Use uint64_t (or long long) to prevent potential overflow on intermediate calculations,
        // even though the final result is guaranteed to fit in a 32-bit signed integer.
        std::vector<uint64_t> dp(n + 1, 0);

        // Base case: There is exactly one way to form an empty string t
        // from any prefix of s (by deleting all characters).
        dp[0] = 1;

        // Iterate through each character of s
        for (int i = 1; i <= m; ++i) {
            // Iterate backwards through t to use results from the previous 's' character
            for (int j = n; j >= 1; --j) {
                // If the characters match, we have a choice
                if (s[i - 1] == t[j - 1]) {
                    // The number of ways to form t's prefix of length j is:
                    // 1. The number of ways to form it WITHOUT using s[i-1] (the current dp[j])
                    // 2. The number of ways to form t's prefix of length j-1 and using s[i-1] for the match (dp[j-1])
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }

        return (int)dp[n];
    }
};