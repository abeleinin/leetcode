#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        
        vector<int> v1(26, 0), v2(26, 0); 

        for (int i = 0; i < s1.size(); i++) {
            ++v1[s1[i] - 'a'];
            ++v2[s2[i] - 'a'];
        }

        if (v1 == v2) return true;

        for (int j = s1.size(); j < s2.size(); j++) {
            ++v2[s2[j] - 'a'];
            --v2[s2[j - s1.size()] - 'a'];

            if (v1 == v2) return true;
        }

        return false;
    }
};
