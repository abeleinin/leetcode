#include <string>

using namespace std;

/**
 * \c Solution1
 * 
 * Recursive approach
 * 1. Branching of recursion depends on number of  left/right parens
 * 2. Use move on rvalue reference to avoid uncessary copy
 * 
 * Time  : O(2^N)
 * Space : O(2^N) stack space
 * 
 * Fun fact: Number of generated parenthesis is a Catalan number:
 * https://en.wikipedia.org/wiki/Catalan_number
 */
class Solution1 {
public:
    void generateParen(int l, int r, string&& curr, vector<string>& st) {
        if (l == 0 && r == 0) {
            st.push_back(curr);
            return;
        }

        if (l > 0) {
            curr.push_back("(");
            generateParen(l-1, r, move(curr), st);
        }

        if (l < r) {
            curr.push_back(")")
            generateParen(l, r-1, move(curr), st);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generateParen(n, n, "", res);
        return res;
    }
};

/**
 * \c Solution2
 * 
 * Fun solution
 * 1. Pre-allocate the size of the curr string
 * 2. Proceed with recursion, but update the parens in reverse order (from n-1 to 0)
 * 
 * Time  : O(2^N)
 * Space : O(2^N) stack space
 */
class Solution2 {
public:
    void generateParen(int l, int r, string& curr, vector<string>& st) {
        if (l == 0 && r == 0) {
            st.push_back(curr);
            return;
        }

        if (l > 0) {
            curr[l+r-1] = ')';
            generateParen(l-1, r, curr, st);
        }

        if (l < r) {
            curr[l+r-1] = '(';
            generateParen(l, r-1, curr, st);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr(2*n, ' ');
        generateParen(n, n, curr, res);
        return res;
    }
};