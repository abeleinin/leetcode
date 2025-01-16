#include <vector>
using namespace std;

// Solution 1
class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr; 
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        createSum(candidates, target, 0);
        return res;
    }
    void createSum(vector<int>& nums, int target, int index){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i = index; i < nums.size(); i++){
            if(target - nums[i] >= 0){
                curr.push_back(nums[i]);
                createSum(nums, target - nums[i], i);
                curr.pop_back();
            }
        }
    }
};