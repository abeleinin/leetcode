#include <vector>
using namespace std;

// Solution 1
// Complete Search
class Solution {
public:
  vector<int> subset;
  vector<vector<int>> res;
  vector<vector<int>> subsets(vector<int>& nums) {
    search(0, nums);
    return res;
  }
  void search(int k, vector<int>& nums){
    if(k >= nums.size()){
      res.push_back(subset);
    } else{
      search(k + 1, nums);
      subset.push_back(nums[k]);
      search(k + 1, nums);
      subset.pop_back();
    }
  }
};