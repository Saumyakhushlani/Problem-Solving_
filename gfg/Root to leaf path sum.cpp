/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/*you are required to
complete this function */
class Solution {
  public:
   bool f=false;
    void solve(Node* root, int k,int sum){
        if(root==nullptr) return;
        sum+=root->data;
        if(root->left==nullptr&&root->right==nullptr && sum==k)f=true;
        solve(root->left,k,sum);
        solve(root->right,k,sum);
        return;
    }
    bool hasPathSum(Node *root, int targetSum) {
        // Your code here
        solve(root,targetSum,0);
        return f;
    }
};