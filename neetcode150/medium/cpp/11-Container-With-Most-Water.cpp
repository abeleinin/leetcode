#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = height.size() - 1;
        int dist = 0; 
        while(i < j) {
            int right = height[i], left = height[j];
            int curr = min(right, left) * (j - i);
            dist = max(dist, curr);
            if(right < left) {
                i++;
            } else {
                j--;
            }
        }
        return dist;
    }
};