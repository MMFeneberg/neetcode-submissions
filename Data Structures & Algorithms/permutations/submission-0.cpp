class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used;
        for (int i = 0; i < nums.size(); i++ ) {
            used.push_back(false);
        }
        solve(result, current, used, nums.size(), nums);
        return result;
    }

    void solve(vector<vector<int>>& result,  vector<int>& current,vector<bool> used, size_t size, vector<int>& nums) {
        if (current.size() == size) {
            result.push_back(current);
            return;
        }
        for (int i = 0; i < size; i++) {
            if (!used[i]) {
                current.push_back(nums[i]);
                used[i] = true;
                solve(result, current, used, size, nums);
                used[i] = false;
                current.pop_back();
            }
        }
    }
};
