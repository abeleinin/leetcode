#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> my_stack;
        for (string token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int v1 = my_stack.top();
                my_stack.pop();
                int v2 = my_stack.top();
                my_stack.pop();
                if (token == "+") {
                    my_stack.push(v2 + v1);
                }
                else if (token == "-") {
                    my_stack.push(v2 - v1);
                }
                else if (token == "/") {
                    my_stack.push(v2 / v1);
                }
                else if (token == "*") {
                    my_stack.push(v2 * v1);
                }
            }
            else {
                my_stack.push(stoi(token));
            }
        }
        return my_stack.top();
    }
};