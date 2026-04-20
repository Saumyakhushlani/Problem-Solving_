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
    int solve(TreeNode* root, TreeNode* parent, TreeNode* grandparent) {
        if (!root) return 0;

        int sum = 0;

        if (grandparent && grandparent->val % 2 == 0) {
            sum += root->val;
        }

        sum += solve(root->left, root, parent);
        sum += solve(root->right, root, parent);

        return sum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, nullptr, nullptr);
    }
};