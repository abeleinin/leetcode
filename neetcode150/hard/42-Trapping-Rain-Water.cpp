#include <vector>

using namespace std;

/**
 * \c Solution1
 * 
 * 1. Calculate max left and right height at position i
 * 2. Use the following equation to calculate the water level at height[i]:
 *      water at height[i] = max(0, min(max_right[i], max_left[i]) - height[i])
 * 
 * Time  : O(N)
 * Space : O(N)
 */
class Solution1 {
public:
    int trap(vector<int>& height) {
        vector<int> max_left(height.size(), 0);
        int prev = 0;
        for (int i = 0; i < height.size(); ++i) {
            max_left[i] = prev;
            prev = max(prev, height[i]);
        }

        vector<int> max_right(height.size(), 0);
        prev = 0;
        for (int i = height.size()-1; i >= 0; --i) {
            max_right[i] = prev;
            prev = max(prev, height[i]);
        }
        
        int tot = 0;
        for (int i = 0; i < height.size(); ++i) {
            tot += max(0, min(max_right[i], max_left[i])-height[i]);
        }

        return tot;
    }
};

/**
 * \c Solution2
 * 
 * 1. Move the left or right pointer inward, depending on which is smaller
 * 2. If height[left] < maxLeft or height[right] < maxRight, then we know water can be trapped above height[i]
 * 3. Otherwise, update maxLeft/maxRight to height[left]/height[right]
 * 
 * Time  : O(N)
 * Space : O(1)
 */
class Solution2 {
public:
    int trap(vector<int>& height) {
        int maxLeft, maxRight, tot = 0;

        int left = 0;
        int right = height.size() - 1;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] < maxLeft) {
                    tot += maxLeft - height[left];
                } else {
                    maxLeft = height[left];
                }
                ++left;
            } else {
                if (height[right] < maxRight) {
                    tot += maxRight - height[right];
                } else {
                    maxRight = height[right];
                }
                --right;
            }
        }

        return tot;
    }
};
