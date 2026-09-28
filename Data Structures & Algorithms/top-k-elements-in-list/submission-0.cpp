class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> buckets(nums.size() + 1);
        unordered_map<int, int> map;

        for (int& n: nums) {
            map[n]++;
        }
        auto it = map.begin(); 
        for (; it != map.end(); it++) {
            buckets[it->second].push_back(it->first);
        }
        int num_val = 0;
        int i = nums.size();
        vector<int> results;
        while (num_val != k) {
            if (!buckets[i].size()) {
                i--;
            } else {
                int j = 0;
                while (num_val != k && j != buckets[i].size()) {
                    results.push_back(buckets[i][j]);
                    num_val++;
                    j++;
                }
                i--;
            }

        }
        return results;
        
    }
};
