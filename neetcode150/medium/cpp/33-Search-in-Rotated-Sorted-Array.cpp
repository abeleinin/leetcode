#include <vector>
using namespace std;

// Solution 1
class Solution {
public:
  int search(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size() - 1;
    while(begin <= end){
      int mid = (begin + end) / 2;
      // Check if the middle value is equal to target
      if(nums[mid] == target){
        return mid;
      } if(nums[begin] > nums[mid] && target >= nums[mid] && target >= nums[begin]){
        end = mid - 1;
      } else if(nums[end] < nums[mid] && target <= nums[mid] && target <= nums[end]){
        begin = mid + 1;
      // Target greater than mid search the upper half of the list
      } else if(target > nums[mid]){
        begin = mid + 1; 
      // Target less than mid search the lower half of the list
      } else if(target < nums[mid]){
        end = mid - 1; 
      }
    }
    return -1;
  }
};