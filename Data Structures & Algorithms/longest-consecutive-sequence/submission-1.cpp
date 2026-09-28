class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for (auto& num : nums) {
            set.insert(num);
        }

        int maximum = 0;

        for (auto& num : nums) {
            if (set.count(num - 1)) {
                continue;
            } else {
                int i = 0;
                while (set.count(num + i)) {
                    i++;
                }
                maximum = max(maximum, i);
            }

        }
        return maximum;
        
    }
};
