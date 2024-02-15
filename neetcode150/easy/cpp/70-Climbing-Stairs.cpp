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

// O(n) time, O(1) space solution
class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) {
            return 1;
        }

        int temp = 0;
        int curr = 1;
        int prev = 0;

        for(int i = 1; i <= n; i++) {
            temp = curr;
            curr += prev;
            prev = temp;
        }
        return curr;
    }
};