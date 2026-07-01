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
    void solve(TreeNode *root,int& ans,int sum){
        if(root==nullptr)return;
        sum = sum*10+root->val;
        if(root->left==NULL&&root->right==NULL){
            ans+=sum;
            return;
        }
        solve(root->left,ans,sum);
        solve(root->right,ans,sum);
        return;
    }
    int sumNumbers(TreeNode* root) {
        int ans=0;
        solve(root,ans,0);
        return ans;
    }
};