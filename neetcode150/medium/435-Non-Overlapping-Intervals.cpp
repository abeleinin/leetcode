#include <vector>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b){ 
            return a[0] < b[0]; 
        });

        int i = 0;
        int j = 1;
        int res = 0;
        while (j < intervals.size()) {
            vector<int>& a = intervals[i];
            vector<int>& b = intervals[j];
            if (a[0] <= b[1] && b[1] < a[1]) {
                if (abs(a[1]-a[0]) > abs(b[1]-b[0])) {
                    i = j;
                }
                ++res;
            } else if (b[0] < a[1] && a[1] <= b[1]) {
                ++res;
            } else if (a[0] == b[0] && a[1] == b[1]) {
                i = j;
                ++res;
            } else {
                i = j;
            }
            j++;
        }
        
        return res;
    }
};