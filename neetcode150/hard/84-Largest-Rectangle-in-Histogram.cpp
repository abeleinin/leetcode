#include <vector>
#include <stack>
#include <utility>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Create a stack of pairs containing heights[i] and the previous smaller index (the index 
 *    of the previous value that is smaller than our current height)
 * 2. When heights[i] is smaller than the top of the stack, we need to terminate the rectangles 
 *    on the stack
 * 3. Width is calculated from the current index i minus the previous smaller index (ie i-stack.top().second)
 * 4. Update previous smaller index and pop
 * 5. Push the current height and the calculated previous smaller index
 * 6. Clean up heights still on the stack
 * 
 * Time  : O(n)
 * Space : O(n)
 */
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        int prevSmallerIdx;
        stack<pair<int,int>> st;
        for (int i = 0; i < heights.size(); ++i) {
            prevSmallerIdx = i;
            while (!st.empty() && heights[i] <= st.top().first) {
                res = max(res, st.top().first * (i-st.top().second));
                prevSmallerIdx = st.top().second;
                st.pop();
            }

            st.push({heights[i], prevSmallerIdx});
        }

        int n = heights.size();
        while (!st.empty()) {
            res = max(res, st.top().first * (n-st.top().second));
            st.pop();
        }

        return res;
    }
};