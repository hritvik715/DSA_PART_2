class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.length();
    int m = p.length();

    // dp[i][j] represents whether s[0...i-1] matches p[0...j-1]
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

    // Empty string matches empty pattern
    dp[0][0] = true;

    // Deals with patterns like a*, a*b*, a*b*c*
    for (int j = 1; j <= m; ++j) {
        if (p[j - 1] == '*') {
            dp[0][j] = dp[0][j - 2]; // '*' matches zero occurrences of the preceding element
        }
    }

    // Fill the dp table
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (p[j - 1] == '.' || p[j - 1] == s[i - 1]) {
                dp[i][j] = dp[i - 1][j - 1]; // Current characters match, so check previous subproblem
            } else if (p[j - 1] == '*') {
                dp[i][j] = dp[i][j - 2]; // '*' matches zero occurrences

                if (p[j - 2] == '.' || p[j - 2] == s[i - 1]) {
                    dp[i][j] = dp[i][j] || dp[i - 1][j]; // '*' matches one or more occurrences
                }
            } else {
                dp[i][j] = false; // Current characters don't match
            }
        }
    }

    return dp[n][m];
    }
};