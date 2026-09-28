class Solution {
public:
    int characterReplacement(string s, int k) {
        int lastMax = 0;
        unordered_map<char,int> seen;
        int left = 0;
        int right = 0;
        int profit = 0;
        while (right != s.size()) {
            
                seen[s[right]]++;
                if (lastMax < seen[s[right]]) {
                    lastMax = seen[s[right]];
                }
                while (right - left + 1 > lastMax + k) {
                    seen[s[left]]--;
                    left++;
                }
                profit = max(profit, right - left + 1);
                right++;
            
        }

        return profit;
    }
};
