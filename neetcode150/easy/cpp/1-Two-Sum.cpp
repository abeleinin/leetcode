#include <vector>
#include <map>
using namespace std;

// Solution 1
class Solution{
public:
  vector<int> twoSum(vector<int>& nums, int target){
    map<int, int> m;
    for(int i = 0; i < nums.size(); i++){
      if(m.find(nums[i]) == m.end()){
        m[target - nums[i]] = i;
      } else{
        return vector<int>({m[nums[i]], i});
      }
    }    
    return vector<int>({-2, -1});
  }
};