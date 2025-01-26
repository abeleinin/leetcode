#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * Iterative Solution
 * 1. Use binary search on a 1D contigous array of size m*n
 * 2. Use middle/n and middle%n to convert 1D contigous array index value into matrix indices
 * 
 * Time  : O(log n)
 * Space : O(1)
 */
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int i = 0;
        int j = m * n - 1;
        int curr, middle;
        while (i <= j) {
            middle = i + (j - i) / 2;
            curr = matrix[middle/n][middle%n];
            if (curr == target) {
                return true;
            }

            if (curr < target) {
                i = middle + 1;
            } else {
                j = middle - 1;
            }
        }
        return false;
    }
};