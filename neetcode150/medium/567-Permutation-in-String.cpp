#include <vector>
#include <string>

using namespace std;

/**
 * \c Solution1
 * 
 * Sorting Approach:
 * Sort input string and compare it to the sorted substr in s2
 * 
 * Time  : O(M * N log N)
 * Space : O(N)
 */
class Solution1 {
public:
    bool checkInclusion(string s1, string s2) {
        sort(s1.begin(), s1.end());

        int i = 0;
        int n = s1.size();
        while ((i+n-1) < s2.size()) {
            string substr = s2.substr(i, s1.size());
            sort(substr.begin(), substr.end());
            if (substr == s1) {
                return true;
            }
            ++i;
        }
        return false;
    }
};

/**
 * \c Solution2
 * 
 * Optimal Approach
 * 1. Store the character frequency of s1 and s2.substr(s1.size())
 * 2. Use cool increment/decrement check approach 
 * 
 * Time  : O(N)
 * Space : O(1)
 */
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;

        vector<int> s1Freq(26, 0);
        vector<int> s2Freq(26, 0);
        for (int i = 0; i < s1.size(); ++i) {
            ++s1Freq[s1[i]-'a'];
            ++s2Freq[s2[i]-'a'];
        }

        if (s1Freq == s2Freq) return true;

        for (int j = s1.size(); j < s2.size(); ++j) {
            ++s2Freq[s2[j]-'a'];
            --s2Freq[s2[j-s1.size()]-'a'];

            if (s1Freq == s2Freq) return true;
        }
        return false;
    }
};
