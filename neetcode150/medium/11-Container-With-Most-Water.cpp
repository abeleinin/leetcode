#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use two pointers and calculate the water container as:
 *          min(height[left], height[right]) * right-left (distance between)
 * 2. Increment/decrement the smaller of the two heights
 * 
 * Time  : O(n)
 * Space : O(1)
 */
class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int res = 0;
        while (i < j){
            int left = height[i];
            int right = height[j];
            int curr = min(left, right) * (j-i);
            res = max(res, curr);
            if (left > right){
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};