/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        queue<TreeNode*> level;
        if (root) {
            level.push(root);
        }
        while (level.size()) {
            vector<int> temp;
            int n = level.size();
            for (int i = 0; i < n; i++) {
                temp.push_back(level.front()->val);
                if (level.front()->left) {
                    level.push(level.front()->left);
                }
                if (level.front()->right) {
                    level.push(level.front()->right);
                }
                level.pop();
            }
            result.push_back(temp);
        }
        return result;
        
    }
};
