class Solution {
    vector<vector<int>> solution;
    vector<int> current;
    int currentSum = 0;
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        calcCombinationSum(0, nums, target);
        return solution;
    }

    void calcCombinationSum(int i, vector<int>& nums, int target) {
        for (; i < nums.size(); i++) {
            if (currentSum + nums[i] > target) {
                continue;
            } else if ((currentSum + nums[i]) == target) {
                current.push_back(nums[i]);
                solution.push_back(current);
                current.pop_back();
                continue;
            } else {
                current.push_back(nums[i]);
                currentSum += nums[i];
                calcCombinationSum(i,nums, target);
                currentSum -= nums[i];
                current.pop_back();
            }
        }
        return;
    }
};
