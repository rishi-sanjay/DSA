/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    bool boss(TreeNode* root, int targetSum, int sum) {
        sum += root->val;
        if (sum == targetSum && (!root->left && !root->right))
            return true;

        bool x = 0, y = 0;
        if (root->left)
            x = boss(root->left, targetSum, sum);
        if (root->right)
            y = boss(root->right, targetSum, sum);
        return x || y;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        return boss(root, targetSum, 0);
    }
};