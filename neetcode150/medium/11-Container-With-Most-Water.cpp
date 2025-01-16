#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = height.size()-1;
        int res = 0;
        while (i < j){
            int left = height[i];
            int right = height[j];
            int curr = min(left, right) * (j-i);
            res = max(res, curr);
            if (left > right){
                --j;
            } else {
                ++i;
            }
        }
        return res;
    }
};