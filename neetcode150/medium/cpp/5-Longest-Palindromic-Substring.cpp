#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string curr;
        string res = "";
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = n-1; i > 0; i--) {
            for (int j = 0; j < n; j++) {
                if (i == j) dp[i][j] = true;
                else if (j-i == 1) dp[i][j] = s[i] == s[j];
                else if (j-i > 1) dp[i][j] = dp[i+1][j-1] && s[i] == s[j];
                if (dp[i][j]) {
                    curr = s.substr(i, j-i+1);
                    res = curr.size() > res.size() ? curr : res;
                }
            }
        } 
        return res;
    }
};