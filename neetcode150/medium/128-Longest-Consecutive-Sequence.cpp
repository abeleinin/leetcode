#include <vector>
#include <set>

using namespace std;

/**
 * \c Solution1
 * 
 * 1. Creates a set of the input vector.
 * 2. Checks if the given number is the "beginning" of a sequence (ie num-1 is not contained in the set)
 * 3. If it's the "beginning", count the sequence length using while loop
 */
class Solution1 {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int res = 0;
        int curr = 0;
        for (int n : s) {
            if (s.find(n - 1) == s.end()) {
                curr = 1; 
                while(s.find(n + 1) != s.end()){
                    curr++;
                    n++;
                }
                res = max(curr, res);
            }
        }
        return res;
    }
};

/**
 * \c Solution2
 * 
 * Same approach as \c Solution1, but uses std::set<>::contains, added in C++20
 * https://en.cppreference.com/w/cpp/container/set/contains
 */
class Solution2 {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());

        int res = 0;
        for (int num : s) {
            if (!s.contains(num-1)) {
                int curr = 1;
                while (s.contains(num+1)) {
                    ++curr;
                    ++num;
                }
                res = max(curr, res);
            }
        }
        return res;
    }
};
