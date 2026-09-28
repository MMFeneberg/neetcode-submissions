class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int low = prices[0];

        int left = 0;
        int right = 0;

        for (; right < prices.size(); right++) {
            if (prices[right] < low) {
                left = right;
                low = prices[right];
            } else {
                profit = max(profit, prices[right] - low);
            }
        }
        return profit;
        
    }
};
