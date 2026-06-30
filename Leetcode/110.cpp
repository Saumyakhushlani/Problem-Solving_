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
    int getH(TreeNode* root){
        queue<TreeNode*>q;
        if(root==nullptr)
            return 0;
        int count=0;
        q.push(root);
        while(!q.empty()){
            count++;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode*curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
        }
        return count;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;
        int l = getH(root->left);
        int r = getH(root->right);
        if(abs(l-r)>1)return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};