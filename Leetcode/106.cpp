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
    int idx;
    TreeNode* solve(vector<int>& post,int low,int high){
        if(low>high)return nullptr;
        TreeNode* node = new TreeNode(post[idx]);
        int id = in[post[idx]];
        idx--;
        node->right=solve(post,id+1,high);
        node->left=solve(post,low,id-1);
        return node;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }
        idx=postorder.size()-1;
        return solve(postorder,0,inorder.size()-1);
    }
};