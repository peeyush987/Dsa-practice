/*
Problem: 36. Valid Sudoku
Link: https://leetcode.com/problems/valid-sudoku/
Difficulty: Medium
complexity:
Time: O(1) since the board size is fixed at 9x9, we can consider the time complexity to be O(1) as it does not depend on the input size     
space: O(1) since we are using a fixed amount of space to store the sets for rows, columns, and boxes, we can consider the space complexity to be O(1) as it does not depend on the input size.
Approach: Hash Set
explanation: We can use three arrays of hash sets to keep track of the numbers we have seen in each row, column, and 3x3 box. As we iterate through each cell in the board, we check if the current number has already been seen in the corresponding row, column, or box. If it has, then the board is not valid and we return false. If it has not been seen, we add the number to the corresponding sets. If we finish iterating through the board without finding any duplicates, then the board is valid and we return true.   
*/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> rows[9];
        unordered_set<char> cols[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }

                char value = board[r][c];
                int boxIndex = (r / 3) * 3 + (c / 3);

                if (rows[r].count(value) || cols[c].count(value) || boxes[boxIndex].count(value)) {
                    return false;
                }

                rows[r].insert(value);
                cols[c].insert(value);
                boxes[boxIndex].insert(value);
            }
        }

        return true;        
    }
};