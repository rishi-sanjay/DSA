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
    void call(TreeNode* node,int l,int c,vector<tuple<int,int,int>>&ans){
        if(node==nullptr) return;
        ans.push_back({c,l,node->val});
        if(node->left)
           call(node->left,l+1,c-1,ans);
         if(node->right)
           call(node->right,l+1,c+1,ans);
        return;
        
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<tuple<int,int,int>>ans;
        vector<vector<int>>res;
        call(root,0,0,ans);
        sort(ans.begin(),ans.end());
        int n=ans.size();
        for(int i=0;i<n;i++){
            vector<int> temp;
           int  min=get<0>(ans[i]);
            while(i<n && (get<0>(ans[i])==min)){
                temp.push_back(get<2>(ans[i]));
                i+=1;
            }
            res.push_back(temp);
            i-=1;
        }
        return res;
    }
};