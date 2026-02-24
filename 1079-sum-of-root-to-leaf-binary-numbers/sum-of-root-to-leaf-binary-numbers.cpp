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
    void boss(TreeNode* head, int &ans, int sum) {
        sum = sum * 2 + head->val;
        if (!head->left && !head->right) {
            ans += sum;
            return;
        }
        if (head->left) {
            boss(head->left, ans, sum);
        }
        if (head->right) {
            boss(head->right, ans, sum);
        }
    }
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        boss(root, ans, 0);
        return ans;
    }
};