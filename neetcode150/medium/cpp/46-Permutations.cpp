#include <vector>
#include <unordered_map>
using namespace std;

// Solution 1
class Solution {
public:
    vector<vector<int>> res;
    vector<int> perm;
    unordered_map<int, int> m;
    vector<vector<int>> permute(vector<int>& nums) {
        search(nums);
        return res;
    }
    void search(vector<int>& nums){
        if(perm.size() == nums.size()){
            res.push_back(perm);
        }
        for(auto n : nums){
            if(m.find(n) != m.end()){
                continue;
            } 
            m[n] = 1;
            perm.push_back(n);
            search(nums);
            m.erase(n);
            perm.pop_back();
        }
    }
};