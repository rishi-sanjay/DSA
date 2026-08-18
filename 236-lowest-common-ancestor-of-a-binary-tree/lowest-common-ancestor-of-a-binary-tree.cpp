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
    bool check(TreeNode* root, TreeNode* p, unordered_map<int, TreeNode*>& m, int r) {
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
        unordered_map<int, TreeNode*>m,n;
        check(root,p,m,0);
        check(root,q,n,0);
        int sz=min(m.size(),n.size());
        for(int i=sz-1;i>=0;i--){
            if(m[i]==n[i]) 
               return m[i];
        }
        return root;
    }
};