#include <vector>
#include <deque>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use deque to maintain the max value at the front position
 * 2. Pop the front value whenever it goes out of the window
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;

        for (int i = 0; i < nums.size(); ++i) {
            while (!q.empty() && nums[i] > q.back()) {
                q.pop_back();
            }
            q.push_back(nums[i]);

            if (i >= k && nums[i-k] == q.front()) {
                q.pop_front();
            }
            
            if (i+1 >= k) {
                res.push_back(q.front());
            }
        }

        return res;
    }
};