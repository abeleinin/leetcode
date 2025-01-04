#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> h;
        for (int n : nums) {
            h[n] += 1;
        }

        vector<vector<int> > b(nums.size()+1);
        for (auto& [n, v] : h) {
            b[v].push_back(n);
        }

        vector<int> result;
        for (int i = b.size()-1; i > 0; --i) {
            vector<int> bucket = b[i];
            while (!bucket.empty()) {
                result.push_back(bucket.back());
                bucket.pop_back();
                --k;
                if (k == 0) {
                    return result;
                }
            }
        }
        
        return result;
    }
};