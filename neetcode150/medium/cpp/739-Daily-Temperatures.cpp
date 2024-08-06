#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temps) {
        int N = temps.size();

        stack<int> st; 
        vector<int> res(N, 0);
        
        for (int i = 0; i < N; i++){
            int curr = temps[i];
            while (!st.empty() && curr > temps[st.top()]) {
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};