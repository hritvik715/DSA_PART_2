class Solution {
public:
    string multiply(string num1, string num2) {
         int m = num1.size(), n = num2.size();
        // Result can have at most m + n digits
        vector<int> pos(m + n, 0);

        // Multiply digit by digit
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int p1 = i + j, p2 = i + j + 1;
                int sum = mul + pos[p2];

                pos[p1] += sum / 10;
                pos[p2] = sum % 10;
            }
        }

        // Convert to string
        string res = "";
        for (int p : pos) {
            if (!(res.empty() && p == 0)) { // Skip leading zeros
                res += ('0' + p);
            }
        }

        return res.empty() ? "0" : res;
     
    }
};