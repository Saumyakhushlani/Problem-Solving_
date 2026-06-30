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
    void inOrderTraversal(Node* root, vector<int> &p){
        if(root == NULL)    return;
        inOrderTraversal(root->left, p);
        p.push_back(root->data);
        inOrderTraversal(root->right, p);      
    }
    int kthSmallest(Node *root, int k) {
        // code here
        vector<int> v; 
        inOrderTraversal(root, v);
        if(k>v.size())return -1;
        return v[k-1];
    }
};