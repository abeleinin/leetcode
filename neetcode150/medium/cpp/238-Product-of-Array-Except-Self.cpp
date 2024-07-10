#include <vector>

using namespace std;

// O(1) extra space solution (The output array does not count as extra space for space complexity analysis).
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int N = nums.size();
        vector<int> out(N);
        
        int t = 1;
        for (int i = 0; i < N; i++){
            out[i] = t;
            t *= nums[i];
        }

        t = 1;
        for (int i = N-1; i >= 0; i--){
            out[i] *= t;
            t *= nums[i];
        }
        return out;
    }
};