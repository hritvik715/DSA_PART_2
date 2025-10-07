class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        if (n != s2.length()) return false;
        if (s1 == s2) return true;
        
        // Use memoization to avoid recomputation
        unordered_map<string, bool> memo;
        return helper(s1, s2, memo);
    }
    
private:
    bool helper(const string& s1, const string& s2, unordered_map<string, bool>& memo) {
        // Base cases
        if (s1 == s2) return true;
        if (s1.length() != s2.length()) return false;
        
        // Create key for memoization
        string key = s1 + "#" + s2;
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }
        
        // Check if characters match (pruning)
        string sorted1 = s1, sorted2 = s2;
        sort(sorted1.begin(), sorted1.end());
        sort(sorted2.begin(), sorted2.end());
        if (sorted1 != sorted2) {
            memo[key] = false;
            return false;
        }
        
        int n = s1.length();
        
        // Try all possible split points
        for (int i = 1; i < n; i++) {
            // Case 1: No swap - compare corresponding parts
            // s1[0:i] with s2[0:i] and s1[i:n] with s2[i:n]
            if (helper(s1.substr(0, i), s2.substr(0, i), memo) &&
                helper(s1.substr(i), s2.substr(i), memo)) {
                memo[key] = true;
                return true;
            }
            
            // Case 2: Swap - compare cross parts
            // s1[0:i] with s2[n-i:n] and s1[i:n] with s2[0:n-i]
            if (helper(s1.substr(0, i), s2.substr(n - i), memo) &&
                helper(s1.substr(i), s2.substr(0, n - i), memo)) {
                memo[key] = true;
                return true;
            }
        }
        
        memo[key] = false;
        return false;
    }
};