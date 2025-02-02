#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Create an array to track character requirements
 * 2. Populate the char array with counts of each character, and initialize a count variable
 * 3. Use two pointers left and right to define a sliding window
 * 5. Once count is less than or equal to 0, try to minimize the window by moving the left pointer
 * 6. Return an empty string if no valid window is found otherwise, return the smallest substring found
 * 
 * Time  : O(m+n)
 * Space : O(1)
 */
class Solution {
public:
    string minWindow(string s, string t) {
        if (s.size() < t.size()) return "";

        vector<int> deficit(58, 0);

        int needCount = t.size();
        for (int i = 0; i < t.size(); ++i) {
            ++deficit[t[i]-'A'];
        }
        
        int i = 0;
        int j = 0;

        int start = 0;
        int minLen = INT_MAX;
        while (i < s.size()) {
            if (j < s.size()) {
                --deficit[s[j]-'A'];
                if (deficit[s[j]-'A'] >= 0) {
                    --needCount;
                }
                ++j;
            } else {
                break;
            }
            
            while (needCount <= 0) {
                if ((j-i) < minLen) {
                    start = i;
                    minLen = j-i;
                }

                ++deficit[s[i]-'A'];
                if (deficit[s[i]-'A'] > 0) {
                    ++needCount;
                }
                ++i;
            }
        }
        
        return (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    }
};