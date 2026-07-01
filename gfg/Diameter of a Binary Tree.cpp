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
    int d= INT_MIN;
    int geth(Node* root){
        if(root==nullptr)return 0;
        int l = geth(root->left);
        int r = geth(root->right);
        int sum = l+r;
        d=max(d,sum);
        return 1+max(l,r);
    }
    int diameter(Node* root) {
        // code here
        geth(root);
        return d;
    }
};