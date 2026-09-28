class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        dfs(nums, result, current, 0);
        return result;
    }

    void dfs(vector<int>& nums, vector<vector<int>>& result,vector<int>& current, int n) {
        result.push_back(current);
        for (int i = n; i < nums.size(); i++) {
            current.push_back(nums[i]);
            dfs(nums,result,current,i+1);
            current.pop_back();
        }
    }
};
