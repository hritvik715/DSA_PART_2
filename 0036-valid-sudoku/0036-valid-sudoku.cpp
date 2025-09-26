class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        std::vector<std::unordered_set<int>> rows(9);
        std::vector<std::unordered_set<int>> cols(9);
        std::vector<std::unordered_set<int>> boxes(9);

        // Iterate through every cell on the 9x9 board.
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char cell_val = board[i][j];

                // Skip empty cells.
                if (cell_val == '.') {
                    continue;
                }

                // --- Check for duplicates ---

                // 1. Check the current row
                if (rows[i].count(cell_val)) {
                    return false; // Found a duplicate in the row
                }
                rows[i].insert(cell_val);

                // 2. Check the current column
                if (cols[j].count(cell_val)) {
                    return false; // Found a duplicate in the column
                }
                cols[j].insert(cell_val);

                // 3. Check the current 3x3 sub-box
                // This formula maps the cell's (i, j) coordinates to a box index (0-8)
                int box_index = (i / 3) * 3 + (j / 3);
                if (boxes[box_index].count(cell_val)) {
                    return false; // Found a duplicate in the 3x3 box
                }
                boxes[box_index].insert(cell_val);
            }
        }

        // If we get through the whole board without finding duplicates, it's valid.
        return true;
    }
};