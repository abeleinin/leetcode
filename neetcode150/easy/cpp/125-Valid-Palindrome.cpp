#include <string>

using namespace std;

// Solution 1
class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        
        if(n == 1){
            return 1;
        }
        
        string str = "";
        for(char c : s){
            if(isalnum(c)){
                str += tolower(c);
            }
        }
        
        int i = 0, j = str.size() - 1;
        while(i < j){
            if(str[i] != str[j]){
                return 0;
            }
            i++;
            j--;
        }
        return 1;
    }
};