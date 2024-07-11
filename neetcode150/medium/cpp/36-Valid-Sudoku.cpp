#include <vector>
#include <map>
#include <set>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<pair<int, int>, set<char>> squares({});
        map<int, set<char>> col({});
        map<int, set<char>> row({});
        for (int i = 0; i < 9; i++){
            for (int j = 0; j < 9; j++){
                char v = board[i][j];
                if (v == '.') {
                    continue;
                }
                pair<int, int> sqr_key = {i/3, j/3};
                set<char>& sqr_set = squares[sqr_key];
                auto a = sqr_set.insert(v);
                auto b = row[i].insert(v);
                auto c = col[j].insert(v);
                if (!a.second || !b.second || !c.second) {
                    return false;
                }
            }
        }    
        return true;
    }
};