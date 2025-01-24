#include <string>
#include <stack>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Push numbers onto stack using std::stoi
 * 2. Perform ops on top two numbers, push result back onto stack
 * 3. return stack.top()
 * 
 * Time  : O(N)
 * Space : O(N)
 */
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;       

        for (string token : tokens) {
            if (token == "*") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 * n1);
            } else if (token == "-") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 - n1);
            } else if (token == "+") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 + n1);
            } else if (token == "/") {
                int n1 = st.top();
                st.pop();
                int n2 = st.top();
                st.pop();
                st.push(n2 / n1);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};