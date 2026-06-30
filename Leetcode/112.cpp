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
    bool f=false;
    void solve(TreeNode* root, int k,int sum){
        if(root==nullptr) return;
        sum+=root->val;
        if(root->left==nullptr&&root->right==nullptr && sum==k)f=true;
        solve(root->left,k,sum);
        solve(root->right,k,sum);
        return;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,targetSum,0);
        return f;
    }
};