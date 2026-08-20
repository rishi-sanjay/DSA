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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        TreeNode* rem = root;
        TreeNode* wow = new TreeNode(val);
        while (node) {
            rem = node;
            if (node->val > val) {
                node = node->left;
            } else {
                node = node->right;
            }
        }
        if(rem==NULL) return wow;
        if (rem->val > val)
            rem->left = wow;
        else
            rem->right = wow;
        return root;
    }
};