class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       unordered_map<int, int> visited;

        for (auto n: nums) {
            visited[n] = 0;
        } 

        int maximum = 0;

        for (int i = 0; i < nums.size(); i++) {
            bool exists = true;
            int count = 1;
            while (exists) {
                if (visited.count(nums[i]+count)) {
                    count++;
                } else {
                    exists = false;
                }
            }
            visited[nums[i]] = count;
            maximum = max(count, maximum);
        }
        return maximum;
    }
};
