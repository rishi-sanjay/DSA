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
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*>s;
        TreeNode* node=root;
        while(true){
            if(node!=nullptr){
                s.push(node);
                node=node->left;
            }else{
                if(s.empty()) break;
                node=s.top();
                s.pop();
                k-=1;
                if(k==0) break;
                node=node->right;
            }
        }
        return node->val;
    }
};