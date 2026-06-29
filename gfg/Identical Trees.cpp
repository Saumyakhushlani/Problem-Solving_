/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution {
  public:
    bool isIdentical(Node* p, Node* q) {
        // code here
         if(p==nullptr && q== nullptr)return true;
        if(p==nullptr || q== nullptr)return false;
        if(p->data!=q->data)return false;
        return isIdentical(p->left,q->left) && isIdentical(p->right,q->right);
    }
};