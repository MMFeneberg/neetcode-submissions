class Solution {
private: 
    vector<vector<int>> solution;
    vector<int> current;
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            subsetCalc(nums, i);
            current.pop_back();
        }
        solution.push_back({});
        return solution;
    }
    void subsetCalc(vector<int>& nums, int i) {
        current.push_back(nums[i]);
        solution.push_back(current);
        i++;
        for (; i < nums.size(); i++) {
            subsetCalc(nums, i);
            current.pop_back();
        }
    }
};
