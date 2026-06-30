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
    
    void solve(TreeNode* root, int k,int sum,vector<vector<int>> &res,vector<int> &v){
        if(root==nullptr) return;
        
        sum+=root->val;
        v.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr && sum==k)res.push_back(v);
        solve(root->left,k,sum,res,v);
        solve(root->right,k,sum,res,v);
        v.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int>v;
        solve(root,targetSum,0,res,v);
        return res;
    }
};