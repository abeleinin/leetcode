#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * Because the input is sorted we can use the left and right pointers and check the curr
 * sum vs. the target the determine if we need to increment or decrement
 * 
 * Time  : O(N)
 * Space : O(1)
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0;
        int r = numbers.size()-1;

        int curr;
        while (l < r){
            curr = numbers[l] + numbers[r];
            if (curr == target){
                return {l+1, r+1};
            } else if (curr > target){
                --r;
            } else {
                ++l;
            }
        }
        return {};
    }
};