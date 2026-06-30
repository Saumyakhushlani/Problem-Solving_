/*
Definition for Node
struct Node {
    int data;
    struct Node *right;
    struct Node *left;
};
*/
bool search(struct Node* root, int val) {
    // code here
    while (root) {
            if (root->data == val)
                break;
            else if (root->data < val)
                root = root->right;
            else if (root->data > val)
                root = root->left;
        }
        return root;
}