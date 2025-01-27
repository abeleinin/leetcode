#include <vector>

using namespace std;

/**
 * \c Solution
 * 
 * 1. Use binary search to determine the minimum bananas-per-hour eating speed k
 * 2. k will be within range (1, max(piles))
 * 3. Calcuate the current total number of hours a middle value gives and adjust high, low based on the total wrt h
 * 4. A single pile has an upper bound of size 10^9 so total must be uint64 or long
 * 
 * Time  : O(n log n)
 * Space : O(1)
 */
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int k = high;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            long total = 0;
            for (int p : piles) {
                total += (p + mid - 1) / mid;
            }

            if (total <= h) {
                k = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return k;
    }
};