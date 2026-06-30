/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        data = data;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    Node* LCA(Node* root, Node* p, Node* q) {
        // code here
        if((p->data <= root->data && q->data >= root->data) ||
            (q->data <= root->data && p->data >= root->data))return root;
        else if(p->data>root->data && q->data>root->data){
            return LCA(root->right,p,q);
        }else{
            return LCA(root->left,p,q);
        }
        return root;
    }
};