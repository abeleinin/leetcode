#includ <vector>

using namespace std;

class Solution {
public:
    bool searchBoard(vector<vector<char>>& board, 
                    const string& word,
                    int curr,
                    int i,
                    int j) 
    {
        if (curr == word.size()) {
            return true;
        }

        char temp = board[i][j];
        board[i][j] = '!';

        bool res = false;
        if (i-1 >= 0 && board[i-1][j] == word[curr]) {
            res = searchBoard(board, word, curr+1, i-1, j);
            if (res) return res;
        }
        if (i+1 < board.size() && board[i+1][j] == word[curr]) {
            res = searchBoard(board, word, curr+1, i+1, j);
            if (res) return res;
        }
        if (j-1 >= 0 && board[i][j-1] == word[curr]) {
            res = searchBoard(board, word, curr+1, i, j-1);
            if (res) return res;
        }
        if (j+1 < board[0].size() && board[i][j+1] == word[curr]) {
            res = searchBoard(board, word, curr+1, i, j+1);
            if (res) return res;
        }

        board[i][j] = temp;
        return res;
    }

    bool exist(vector<vector<char>>& board, string word) {
        bool res = false;
        for (int i = 0; i < board.size(); i++){
            for (int j = 0; j < board[0].size(); j++){
                if(board[i][j] == word[0]) {
                    res = searchBoard(board, word, 1, i, j);
                }
                if (res) return res;
            }
        }
        return res;
    }
};