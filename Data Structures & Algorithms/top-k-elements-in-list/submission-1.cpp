class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        vector<vector<int>> buckets;

        for (auto n : nums) {

            count[n] = 1 + count[n];
        }

        buckets.resize(nums.size() + 1);

        for (auto c: count) {
            std::cout << c.second << "\n";
            buckets[c.second].push_back(c.first);
        }

        int counter = 0;

        vector<int> solution;

        while (k > 0 && counter < buckets.size()) {
            std::cout << counter << "\n";
            int bucketSize = buckets[buckets.size()-1 - counter].size();
            int i = 0;
            while (k > 0 && i < bucketSize) {
                solution.push_back(buckets[buckets.size() - counter - 1][i]);
                i++;
                k--;
    
            }
            counter++;
        }

    return solution;

    }
};
