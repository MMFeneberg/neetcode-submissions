class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int diff = 0;
        int left = 0;
        int right = 0;
        while (right < prices.size()) {
            if (prices[right] < prices[left]) {
                left = right;
            }
            if (diff < prices[right] - prices[left]) {
                diff = prices[right] - prices[left];
            }
            right++;
        }
        return diff;
    }
};
