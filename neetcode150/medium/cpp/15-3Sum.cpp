#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int curr;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size()-2; i++){
            if (i > 0 && nums[i] == nums[i - 1]){
                continue;
            }
            int l = i+1;
            int r = nums.size()-1;
            while (l < r) {
                curr = nums[i] + nums[l] + nums[r];
                if (curr == 0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[r] == nums[r-1]) {
                        --r;
                    }
                    while (l < r && nums[l] == nums[l+1]) {
                        ++l;
                    }
                    ++l;
                    --r;
                } else if (curr > 0) {
                    --r;
                } else {
                    ++l;
                }
            } 
        }
        return res;
    }
};