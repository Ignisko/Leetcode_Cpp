/*
Given an m x n grid of characters board and a string word, return true if word exists in the grid.

The word can be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

 

Example 1:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true
Example 2:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true
Example 3:


Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
 

Constraints:

m == board.length
n = board[i].length
1 <= m, n <= 6
1 <= word.length <= 15
board and word consists of only lowercase and uppercase English letters.
 

Follow up: Could you use search pruning to make your solution faster with a larger board? */

#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<char>>& board, int i, int j, string& word, int wordIndex) {
        if (wordIndex == word.length()) return true; // Found the word
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[wordIndex]) return false; // Pruning

        char temp = board[i][j];
        board[i][j] = '#'; // Mark as visited
        bool found = dfs(board, i+1, j, word, wordIndex+1) || 
                     dfs(board, i-1, j, word, wordIndex+1) || 
                     dfs(board, i, j+1, word, wordIndex+1) || 
                     dfs(board, i, j-1, word, wordIndex+1);
        board[i][j] = temp; // Backtrack
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
