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
    unordered_map<int,int>in;
    int idx=0;
    TreeNode* solve(vector<int>& preorder,int low,int high){
        if(low>high)return nullptr;
        TreeNode* node = new TreeNode(preorder[idx]);
        int id = in[preorder[idx]];
        idx++;
        node->left=solve(preorder,low,id-1);
        node->right=solve(preorder,id+1,high);
        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }
        return solve(preorder,0,inorder.size()-1);
    }
};