#include <vector>

using namespace std;

class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int N = speed.size();
        if (N == 1) return 1;

        vector<pair<int, double>> ps(N); 
        for (int i = 0; i < N; i++){
            ps[i] = {position[i], speed[i]};
        }

        sort(ps.begin(), ps.end());

        double curr, time;
        int res = 0;
        int i = N-1;
        time = (target - ps[i].first) / ps[i].second;
        for (int j = N-2; j >= 0; j--) {
            curr = (target - ps[j].first) / ps[j].second;
            if (curr <= time) {
                curr = min(time, curr);
            } else {
                time = curr;
                ++res;
            }
        }
        
        return res + 1;
    }
};