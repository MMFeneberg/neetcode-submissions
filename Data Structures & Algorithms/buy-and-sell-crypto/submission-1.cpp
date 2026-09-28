class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int left = 0;
        int minn = prices[0];
        int maxx = 0;

        while (left < prices.size()) {
            if (prices[left] < minn) {
                profit = max(profit, maxx - minn);
                minn = prices[left];
                maxx = 0;
                left++;
            } else {
                if (maxx < prices[left]) {
                    maxx = prices[left];
                }
                left++;
            }
        }
        profit = max(profit, maxx - minn);

        return profit;
    }
};
