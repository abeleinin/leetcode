#include <unordered_map>

// O(n) time, O(n) space solution
class Solution {
public:
    std::unordered_map<int, int> stairs = {{1, 1}, {2, 2}};
    int climbStairs(int n) {
        if (n < 0) {
            return 0;
        }
        if (stairs.find(n) != stairs.end()){
            return stairs[n];
        }
        stairs[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return stairs[n];
    }
};