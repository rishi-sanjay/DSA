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
    TreeNode* creat(vector<int>& preorder, int &i, int boun) {
        if (i == preorder.size() || preorder[i] > boun)
            return NULL;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = creat(preorder, i, node->val);
        node->right = creat(preorder, i , boun);
        return node;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return creat(preorder, i, INT_MAX);
    }
};