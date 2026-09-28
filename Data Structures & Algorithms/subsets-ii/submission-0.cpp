class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        vector<int> current;
        sort(nums.begin(),nums.end());
        findSubsets(result,nums,current,n,0);
        return result;
    }

    void findSubsets(vector<vector<int>>& result,vector<int>& nums, vector<int>& current, int n, int it ) {
        result.push_back(current);
        if (it == n) {

            return;
        }
        for (int i = it; i < n; i++) {
            current.push_back(nums[i]);
            findSubsets(result,nums,current,n,i+1);
            current.pop_back();
            while (nums[i] == nums[i+1]) {
                i = i+1;
            }
        }
    }
};
