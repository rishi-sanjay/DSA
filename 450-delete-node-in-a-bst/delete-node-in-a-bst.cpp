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
    TreeNode* pata(TreeNode* node){
        if(!node->right) return node;
         return pata(node->right);
    }
    TreeNode* help(TreeNode* node){
        if(!node->left && !node->right) return nullptr;
        if(!node->left || !node->right){
            if(node->left) return node->left;
            else return node->right;
        }
        TreeNode *rightwaala=node->right;
        pata(node->left)->right=rightwaala;
        return node->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return root;
        if (root->val == key)
            return help(root);
        TreeNode* node = root;
        while (node) {
            if (node->val >= key) {
                if (node->left && node->left->val == key) {
                    node->left = help(node->left);
                    break;
                } else
                    node = node->left;
            } else {
                if (node->right && node->right->val == key) {
                    node->right = help(node->right);
                    break;
                } else
                    node = node->right;
            }
        }
        return root;
    }
};