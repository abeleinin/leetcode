#include <vector>
#include <set>
using namespace std;

// Solution 1
// Note: Slow in C++
class Solution{
public:
  // Check if the length of the set 
  bool containsDuplicate(vector<int>& nums){
    set<int> s;
    for(int n : nums){
      s.insert(n);
    }
    return s.size() != nums.size();
  }
};

// Solution 2
class Solution{
public:
  bool containsDuplicate(vector<int>& nums){
    // Sort the vector
    sort(nums.begin(), nums.end());
    int x = nums[0];
    // if n == n + 1 then the vector contains a duplicate
    for(int i = 1; i < nums.size(); i++){
      if(x == nums[i]){
        return true;
      }
      // set n = n + 1
      x = nums[i];
    }
    return false;
  }
};