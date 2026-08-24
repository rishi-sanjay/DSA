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
    int le(TreeNode* node){
        int l=0;
        while(node){
            l+=1;
            node=node->left;
        }
        return l;
    }
     int ri(TreeNode* node){
        int l=0;
        while(node){
            l+=1;
            node=node->right;
        }
        return l;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh=le(root);
        int rh=ri(root);
        if(lh==rh) 
           return ((1<<lh) -1);
        else 
            return 1 + countNodes(root->left) +countNodes(root->right);
    }
};