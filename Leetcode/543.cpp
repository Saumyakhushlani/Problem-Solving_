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
    int d= INT_MIN;
    int geth(TreeNode* root){
        if(root==nullptr)return 0;
        int l = geth(root->left);
        int r = geth(root->right);
        int sum = l+r;
        d=max(d,sum);
        return 1+max(l,r);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        geth(root);
        return d;
    }
};