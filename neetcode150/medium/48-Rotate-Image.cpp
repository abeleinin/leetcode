#include <vector>
using namespace std;

// Solution 1
class Solution{
public:
  void rotate(vector<vector<int>>& matrix){
    vector<vector<int>> copy(matrix);
    for(int r = 0; r < matrix.size(); r++){
      for(int c = 0; c < matrix.size(); c++){
        matrix[r][c] = copy[matrix.size() - 1 - c][r];
      }
    }
  }
};

// Solution 2
class Solution2 {
public:
    void rotate(vector<vector<int>>& matrix) {
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[i].size(); j++) {
                if (j > i) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }
        }

        for (int i = 0; i < matrix.size(); i++) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};