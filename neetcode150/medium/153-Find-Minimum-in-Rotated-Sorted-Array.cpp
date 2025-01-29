#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use the top number of the array to determine how it's rotated
 * 2. Adjust i and j indices accordingly
 * 
 * Time  : O(log n)
 * Space : O(1)
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            int mid = i + (j - i) / 2;
            if (nums[mid] < nums[j]) {
                j = mid;
            } else {
                i = mid + 1;
            }
        }
        return nums[i];
    }
};