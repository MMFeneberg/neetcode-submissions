class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        int currentSum = 0;
        dfs(candidates, target, result, current, 0, currentSum);
        return result;
    }

    void dfs(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int n, int currentSum) {
        if (currentSum == target) {
            result.push_back(current);
            return;
        }

        for (int i = n; i < candidates.size(); i++) {
            
            if (currentSum > target) {
                break;
            } 
            current.push_back(candidates[i]);
            currentSum += candidates[i];
            dfs(candidates, target, result, current, i+1, currentSum);
            current.pop_back();
            currentSum -= candidates[i];
            while (i < candidates.size() -1 && candidates[i] == candidates[i+1] ) {
                i++;
            }
            
        }
    }
};
