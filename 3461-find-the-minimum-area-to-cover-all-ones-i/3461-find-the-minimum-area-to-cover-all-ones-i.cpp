class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
         int minRow = INT_MAX;
        int maxRow = INT_MIN;
        int minCol = INT_MAX;
        int maxCol = INT_MIN;

        int rows = grid.size();
        int cols = grid[0].size();

        bool foundOne = false;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 1) {
                    foundOne = true;
                    minRow = std::min(minRow, i);
                    maxRow = std::max(maxRow, i);
                    minCol = std::min(minCol, j);
                    maxCol = std::max(maxCol, j);
                }
            }
        }

        // Handle the case where there are no 1s in the grid
        if (!foundOne) {
            return 0;
        }

        int height = maxRow - minRow + 1;
        int width = maxCol - minCol + 1;

        return height * width;
    }
};