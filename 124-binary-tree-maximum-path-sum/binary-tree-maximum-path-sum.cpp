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
int  well(TreeNode* node,int & sum){
    if(node==nullptr) return 0;
    int lh=0,rh=0;
    lh=well(node->left,sum);
    rh=well(node->right,sum);
    int x=node->val+lh;
    int y=node->val+rh;
    sum=max({sum,x,y});
    sum=max({sum,node->val+rh+lh,node->val});
    if(lh<0 ) lh=0;
    if(rh<0) rh=0;
    return node->val + max(lh,rh);
}
    int maxPathSum(TreeNode* root) {
         int sum=INT_MIN;
         int x=well(root,sum);
         return sum;
    }
};