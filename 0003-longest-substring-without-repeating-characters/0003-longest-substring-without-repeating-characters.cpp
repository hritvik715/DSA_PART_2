class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        std::vector<int> charIndex(128, -1);
        
        int maxLength = 0;
        // 'left' is the starting index of the current non-repeating substring (our window).
        int left = 0;

        // 'right' is the ending index of the current non-repeating substring.
        for (int right = 0; right < s.length(); ++right) {
            char currentChar = s[right];

            // Check if the current character has been seen before *within the current window*.
            // The window starts at 'left'. If the last seen index of the character
            // is greater than or equal to 'left', we have a repeat inside our window.
            if (charIndex[currentChar] >= left) {
                // Move the start of our window to the position right after
                // the last occurrence of the current character.
                left = charIndex[currentChar] + 1;
            }

            // Update the last seen index for the current character to its current position.
            charIndex[currentChar] = right;

            // Calculate the length of the current valid window (from 'left' to 'right')
            // and update maxLength if the current window is longer.
            maxLength = std::max(maxLength, right - left + 1);
        }

        return maxLength;
    }
};