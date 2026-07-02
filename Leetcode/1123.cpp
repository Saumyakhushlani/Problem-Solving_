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
    unordered_map<int, int> mpp;
    int mx = 0;
    void depth(TreeNode* root, int d) {
        if (root == nullptr)
            return;
        mx = max(mx, d);
        mpp[root->val] = d;
        depth(root->left, d + 1);
        depth(root->right, d + 1);
    }

    TreeNode* LCA(TreeNode* root) {
        if (root == nullptr || mpp[root->val] == mx)
            return root;
        TreeNode* l = LCA(root->left);
        TreeNode* r = LCA(root->right);
        if (l && r)
            return root;
        if (l == nullptr)
            return r;
        return l;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        depth(root, 0);
        return LCA(root);
    }
};