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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> t;
        if (root == nullptr) return t;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                v.push_back(temp->val);
                if (temp->left != nullptr)
                    q.push(temp->left);

                if (temp->right != nullptr)
                    q.push(temp->right);
                q.pop();
            }
            t.push_back(v);
        }
        reverse(t.begin(),t.end());
        return t;
    }
};