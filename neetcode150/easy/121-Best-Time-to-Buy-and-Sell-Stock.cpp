#include <vector>

using namespace std;

// Solution 1
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int price = 0;
        for(int i = 1; i < prices.size(); i++){
            int curr = prices[i] - min_val;
            if(curr > price){
                price = curr;
            } else if(prices[i] < min_val){
                min_val = prices[i];
            }
        }
        return price;
    }
};