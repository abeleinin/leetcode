#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int res = 0;
        int curr = 0;
        for (int n : s) {
            if (s.find(n - 1) == s.end()) {
                curr = 1; 
                while(s.find(n + 1) != s.end()){
                    curr++;
                    n++;
                }
                res = max(curr, res);
            }
        }
        return res;
    }
};