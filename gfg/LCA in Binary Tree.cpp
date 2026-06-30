/*
Definition for Node
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
    int solve(Node* root, int p, int q , Node* &ans){
        if(root==nullptr)return 0;
        int left = solve(root->left,p,q,ans);
        int right = solve(root->right,p,q,ans);
        int self = 0;
        if(root->data==p || root->data==q) self=1;
        int total = left+right+self;
        if(total==2 && ans==nullptr){
            ans = root;
        }
        return total;
    }
    Node* lca(Node* root, int p, int q) {
        //  code here
        Node* ans=nullptr;
        solve(root,p,q,ans);
        return ans;
        
    }
};