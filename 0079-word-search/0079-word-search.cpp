#include <vector>
#include <string>

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        int rows = board.size();
        int cols = board[0].size();

        // Iterate through each cell of the board to find a potential starting point.
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                // Start the DFS search from the cell (i, j).
                // If it finds the word, we can return true immediately.
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }

        // If the loops complete without finding the word, it doesn't exist.
        return false;
    }

private:
    /**
     * @brief Performs a Depth First Search to find the word.
     * @param board The grid of characters.
     * @param word The word to search for.
     * @param r The current row index.
     * @param c The current column index.
     * @param index The index of the character we are currently looking for in 'word'.
     * @return True if a path is found, false otherwise.
     */
    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int r, int c, int index) {
        // --- Base Cases for the recursion ---

        // 1. Success: If we've found all characters of the word.
        if (index == word.length()) {
            return true;
        }

        // 2. Failure: If we are out of bounds or the character doesn't match.
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        // --- Backtracking Logic ---
        
        // Temporarily mark the current cell as visited to avoid reusing it in the same path.
        char temp = board[r][c];
        board[r][c] = '#'; 

        // Explore neighbors (Down, Up, Right, Left)
        bool found = dfs(board, word, r + 1, c, index + 1) ||
                     dfs(board, word, r - 1, c, index + 1) ||
                     dfs(board, word, r, c + 1, index + 1) ||
                     dfs(board, word, r, c - 1, index + 1);

        // Backtrack: Restore the original character so it can be used in other potential paths.
        board[r][c] = temp;

        return found;
    }
};