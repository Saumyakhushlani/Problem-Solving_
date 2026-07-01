/*
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
  Node* prev=nullptr;
    bool ans = true;
    void solve(Node* root){
        if(root==nullptr)return;
        solve(root->left);
        if(prev==nullptr){
            prev=root;
        }else if(root->data<=prev->data){
            ans = false;
        }
        prev=root;
        solve(root->right);
        return;
    }
    bool isBST(Node* root) {
        // code here
        solve(root);
        return ans;
    }
};