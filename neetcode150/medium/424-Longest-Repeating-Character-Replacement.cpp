#include <map>

using namespace std;

// Optimal Time and space
class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);

        int i = 0;
        int j = 0;

        int res = 0;
        int curr = 0;

        while (j < s.size()) {
            int& val = freq[s[j] - 'A'];
            ++val;

            curr = max(curr, val);

            while ((j-i+1)-curr > k) {
                --freq[s[i] - 'A'];
                ++i;
            }

            res = max(res, j-i+1);
            ++j;
        }

        return res;
    }
};

// Initial Solution
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> h;

        int i = 0;
        int j = 0;

        int res = 0;

        int curr = 0;

        while (j < s.size()) {
            auto [it, inserted] = h.try_emplace(s[j], 1);
            if (!inserted) {
                ++it->second;
            }

            curr = max(curr, it->second);

            while ((j-i+1)-curr > k) {
                int& v = h[s[i]];
                --v;
                if (v == 0) { h.erase(s[i]); }
                ++i;
            }

            res = max(res, j-i+1);
            ++j;
        }

        return res;
    }
};