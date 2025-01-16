#include <vector>

using namespace std;

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