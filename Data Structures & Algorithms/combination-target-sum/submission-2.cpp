class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(nums.begin(),nums.end());
        int currentSum = 0;
        dfs(nums, target, result, current, currentSum, 0);
        return result;
    }

    void dfs(vector<int>& nums, int target, vector<vector<int>>& result, vector<int>& current, int& currentSum, int n) {
        cout << "dfs: " << target << ", " << currentSum << ", " << n << "\n";
        if (currentSum == target) {
            result.push_back(current);
            return;
        }
        int last = INT_MAX;
        for (int i = n; i < nums.size(); i++) {
            if (nums[i] == last) {
                while (i < nums.size() && nums[i] == last) {
                    i++;
                }
            }
            current.push_back(nums[i]);
            currentSum += nums[i];
            if (currentSum > target) {
                current.pop_back();
                currentSum -= nums[i];
                return;
            }
            dfs(nums,target,result,current, currentSum, i);
            current.pop_back();
            currentSum -= nums[i];
            last = nums[i];
        }
    }
};
