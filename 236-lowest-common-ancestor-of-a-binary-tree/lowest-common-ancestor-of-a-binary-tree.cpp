/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool check(TreeNode* root, TreeNode* p, unordered_map<int, TreeNode*>& m,
               int r) {
        if (root == nullptr)
            return false;
        m[r] = root;
        if (p == root)
            return true;
        if (check(root->left, p, m, r + 1) || check(root->right, p, m, r + 1))
            return true;
        m.erase(r);
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL || root == p || root == q)
            return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if (left == NULL)
            return right;
        else if (right == NULL)
            return left;
        else
         return root;
    }
};