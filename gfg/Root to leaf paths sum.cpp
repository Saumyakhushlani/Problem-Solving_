/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

class Solution {
  public:
    void solve(Node *root,int& ans,int sum){
        if(root==nullptr)return;
        sum = sum*10+root->data;
        if(root->left==NULL&&root->right==NULL){
            ans+=sum;
            return;
        }
        solve(root->left,ans,sum);
        solve(root->right,ans,sum);
        return;
    }
    int treePathsSum(Node *root) {
        // code here.
        int ans=0;
        solve(root,ans,0);
        return ans;
    }
};