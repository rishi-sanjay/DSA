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
    vector<int> rightSideView(TreeNode* root) {
        map<int, int> m;
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        if (root == nullptr)
            return ans;
        q.push({root, 0});
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int val = p.second;
            if (m.find(val) == m.end())
                m[val] = node->val;
            if (node->right) {
                q.push({node->right, val + 1});
            }
            if (node->left) {
                q.push({node->left, val + 1});
            }
        }
        for (auto val : m)
            ans.push_back(val.second);
        return ans;
    }
};