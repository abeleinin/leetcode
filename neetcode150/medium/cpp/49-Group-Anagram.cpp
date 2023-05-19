#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

// Solution 1
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> h;
        for(int i = 0; i < strs.size(); i++) {
            string val = strs[i];
            sort(val.begin(), val.end());
            h[val].push_back(strs[i]);
        }
        vector<vector<string>> sol;
        for(auto pair : h) {
            sol.push_back(pair.second);
        }
        return sol;
    }
};