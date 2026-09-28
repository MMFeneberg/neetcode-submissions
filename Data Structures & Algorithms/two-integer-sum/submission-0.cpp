class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> solution;
        vector<int> result;

        for (int i = 0; i < nums.size(); i++) {
            if (solution.count(target - nums[i])) {
                result.push_back(solution[target - nums[i]]);
                result.push_back(i);
                return result;
            }
            solution[nums[i]] = i;
        }
    }
};
