#include <string>

using namespace std;

/**
 * \c Solution1
 * 
 * 1. Check base cases (ie size == 0 || size == 1)
 * 2. Create "clean" string without non-alphanumeric characters and uses lowercase character (ie isalnum and tolower utils)
 * 3. Use two-pointer technique to compare beginning and end characters
 */
class Solution1 {
public:
    bool isPalindrome(string s) {
        if(s.size() == 1){
            return true;
        }
        
        string clean = "";
        for(char c : s){
            if(isalnum(c)){
                clean += tolower(c);
            }
        }
        
        int i = 0;
        int j = clean.size() - 1;
        while(i < j){
            if(clean[i] != clean[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};

/**
 * \c Solution2
 * 
 * Similar to \c Solution1 but doesn't use auxiliary "clean" string, saving space.
 */
class Solution2 {
public:
    bool isPalindrome(string s) {
        if (s.size() == 0 || s.size() == 1) {
            return true;
        }
        
        int i = 0;
        int j = s.size()-1;
        while(i < j) {
            if (!isalnum(s[i])) {
                ++i;
                continue;
            }

            if (!isalnum(s[j])) {
                --j;
                continue;
            }

            if (tolower(s[i]) != tolower(s[j])) return false;
            ++i;
            --j;
        }

        return true;
    }
};