class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if (triangle.empty()) {
            return 0;
        }

        // Start from the second to last row and move upwards.
        for (int i = triangle.size() - 2; i >= 0; --i) {
            // Iterate through each element in the current row.
            for (int j = 0; j < triangle[i].size(); ++j) {
                // Update the current element with the minimum path sum from the row below.
                // The minimum path from here is the current value plus the minimum
                // of its two adjacent elements in the next row.
                triangle[i][j] += std::min(triangle[i + 1][j], triangle[i + 1][j + 1]);
            }
        }

        // The minimum total path sum is now stored at the top of the triangle.
        return triangle[0][0];
    }
};