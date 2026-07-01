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
    TreeNode* prev=nullptr;
    bool ans = true;
    void solve(TreeNode* root){
        if(root==nullptr)return;
        solve(root->left);
        if(prev==nullptr){
            prev=root;
        }else if(root->val<=prev->val){
            ans = false;
        }
        prev=root;
        solve(root->right);
        return;
    }
    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};