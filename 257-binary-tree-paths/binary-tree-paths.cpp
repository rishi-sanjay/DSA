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
    void pinn(TreeNode* node, vector<string>& ans, string temp) {
        if (node == nullptr)
            return;
        temp += to_string(node->val);
        if (!node->right && !node->left) {
            ans.push_back(temp);
            return;
        }
            if (node->left)
                pinn(node->left, ans, temp+"->");
            if (node->right)
                pinn(node->right, ans, temp+"->");
            temp.pop_back();
            return;
        }
        vector<string> binaryTreePaths(TreeNode * root) {
            vector<string> ans;
            pinn(root, ans, "");
            return ans;
        }
    };