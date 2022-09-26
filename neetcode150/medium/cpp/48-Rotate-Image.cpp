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