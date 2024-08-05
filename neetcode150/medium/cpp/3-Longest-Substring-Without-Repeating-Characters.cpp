#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        set<char> chars = {};
        int i = 0;
        int j = 0;
        int res = 0;
        while (j < s.size()){
            auto [it, inserted] = chars.insert(s[j]);
            if (!inserted) {
                while (s[i] != s[j]) {
                    chars.erase(s[i]);
                    ++i;
                }
                ++i;
            } 
            res = max(res, (int)chars.size());
            j++;
        }
        return res;
    }
};