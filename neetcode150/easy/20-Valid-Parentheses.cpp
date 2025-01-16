#include <stack>
#include <string>
using namespace std;

// Solution 1
class Solution {
public:
    bool isValid(string s) {
        stack<char> parens;
        if(s.length() % 2 != 0){
          return false;
        }
        for(char c : s){
            if(c == '{' || c == '(' || c == '['){
                parens.push(c);
            } else if(parens.size() > 0){
                if(c == '}' && parens.top() == '{'){
                    parens.pop();
                } else if(c == ']' && parens.top() == '['){
                    parens.pop();
                } else if(c == ')' && parens.top() == '('){
                    parens.pop();
                } else{
                    return false;
                }
            } else{
                return false;
            }
        } 
        return parens.size() == 0;
    }
};