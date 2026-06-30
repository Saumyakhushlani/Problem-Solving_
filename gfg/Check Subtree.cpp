/* Structure of a Tree Node
class Node {
  public:
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    bool isMirror( Node* left,  Node* right) {
        if (left == nullptr && right == nullptr)
            return true;

        if (left == nullptr || right == nullptr)
            return false;

        if (left->data != right->data)
            return false;

        return isMirror(left->left, right->left) &&
               isMirror(left->right, right->right);
    }
    bool isSubTree(Node *root, Node *subRoot) {
        // code here
          if(root==nullptr)return false;
        if(root->data==subRoot->data && isMirror(root,subRoot)) return true;
        return isSubTree(root->left,subRoot) || isSubTree(root->right,subRoot);
    }
};