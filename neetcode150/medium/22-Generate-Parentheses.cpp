#include <string>

using namespace std;

class Solution {
public:
    vector<string> all;
    void genParen(string curr, int left, int right) {
        if (right == 0) {
            all.push_back(curr);
            return;
        }
        if (left > 0) {
            genParen(curr + "(", left - 1, right);
        }
        if (left < right) {
            genParen(curr + ")", left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        genParen("", n, n);
        return all;
    }
};