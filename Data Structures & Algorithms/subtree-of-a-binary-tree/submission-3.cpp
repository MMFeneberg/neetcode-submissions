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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (!root) {
            return false;
        }
        if (identical(root, subRoot)) {
            return true;
        }
        bool left = isSubtree(root->left,subRoot);
        bool right = isSubtree(root->right,subRoot);
        if (left || right) {
            return true;
        }
        return false;
    }

    bool identical(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) {
            return true;
        } 
        if (!root||!subRoot) {
            return false;
        }
        if (root->val == subRoot->val) {
            bool left = identical(root->left,subRoot->left);
            bool right = identical(root->right,subRoot->right);
            if (left && right) {
             return true;
            }
            return false;
        }
        return false;

    }
};
