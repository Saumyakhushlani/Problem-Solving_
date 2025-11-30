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
    void inOrderTraversal(TreeNode* root, vector<int> &p){
        if(root == NULL)    return;
        inOrderTraversal(root->left, p);
        p.push_back(root->val);
        inOrderTraversal(root->right, p);      
    }
    int kthSmallest(TreeNode* root, int k) {
        vector<int> v; 
        inOrderTraversal(root, v);
        return v[k-1];
    }
};