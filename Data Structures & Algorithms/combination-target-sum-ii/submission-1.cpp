class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        vector<vector<int>> solution;
        vector<int> current;
        int i = 0;

        dfs(candidates, solution, current, i, target);
        return solution;

    }

    void dfs(vector<int>& candidates, vector<vector<int>>& solution, vector<int>& current, int i, int target) {
        int prev = -1;
        for (; i < candidates.size(); i++) {
            if (candidates[i] > target) {
                return;
            } else if (candidates[i] == prev) {
                continue;
            }
            
            else if (candidates[i] == target) {
                current.push_back(candidates[i]);
                solution.push_back(current);
                current.pop_back();
                return;
            
            } else {
                current.push_back(candidates[i]);
                dfs(candidates, solution, current, (i+1), (target - candidates[i]));
                current.pop_back();
            }
            prev = candidates[i];
        }
    }


};
