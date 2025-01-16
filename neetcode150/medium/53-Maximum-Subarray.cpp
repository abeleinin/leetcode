#include <vector>

using namespace std;

// Solution 1
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int tot = 0;
        int best = nums[0];
        for(int n : nums){
            if(n > tot && tot < 0){
                tot = 0; 
            }
            tot += n;
            best = max(tot, best);
        }
        return best; 
    }
};