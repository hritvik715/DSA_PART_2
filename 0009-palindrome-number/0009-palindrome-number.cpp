class Solution {
public:
    bool isPalindrome(int x) {
         if (x < 0) {
            return false;
        }

        long long reversed_num = 0;
        int original_num = x;

        while (x > 0) {
            int digit = x % 10;
            reversed_num = reversed_num * 10 + digit;
            x /= 10;
        }

        return original_num == reversed_num;
    }
};