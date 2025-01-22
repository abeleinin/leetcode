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

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int res = 0;
        for (auto num : s) {
            if (!s.contains(num-1)) {
                int curr = 1;
                while (s.contains(num+1)) {
                    ++curr;
                    ++num;
                }
                res = max(curr, res);
            }
        }
        return res;
    }
};
