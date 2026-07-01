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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        int cnt = 0;
        q.push(root);
        bool f = false;
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            if (tmp == nullptr) {
                f = true;
            } else {
                if (!f)
                    cnt++;
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return cnt;
    }
};