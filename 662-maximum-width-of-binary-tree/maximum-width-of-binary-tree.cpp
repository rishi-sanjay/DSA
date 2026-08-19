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
    int widthOfBinaryTree(TreeNode* root) {
        int ans=0;
        if(root==NULL) return ans;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            int fir,las;
            int mnn=q.front().second;
            int sz=q.size();
            for(int i=0;i<sz;i++){
                TreeNode* node=q.front().first;
                int curr=q.front().second-mnn;
                q.pop();
                if(i==0) fir=curr;
                if(i==sz-1) las=curr;
                if(node->left)
                  q.push({node->left,(long long)2*curr+1});
                if(node->right)
                q.push({node->right,(long long)2*curr+2});
            }
            ans=max(ans,las-fir+1);
        }
        return ans;
    }
};