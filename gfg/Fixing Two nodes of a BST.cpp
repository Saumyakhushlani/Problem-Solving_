/*
class Node
{
    public:
    int data;
    Node *left, *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* first = nullptr;
    Node* second = nullptr;
    Node* prev = nullptr;
    void solve(Node* node) {
        if (!node) return;

        solve(node->left);

        if (prev && prev->data > node->data) {
            if (!first) first = prev;
            second = node;
        }

        prev = node;

        solve(node->right);
    }
    void correctBST(Node* root) {
        // add code here.
        solve(root);
        swap(first->data, second->data);
    }
};