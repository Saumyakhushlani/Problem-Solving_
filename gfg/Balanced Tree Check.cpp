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
    int getH(Node* root){
        queue<Node*>q;
        if(root==nullptr)
            return 0;
        int count=0;
        q.push(root);
        while(!q.empty()){
            count++;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node*curr=q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
        }
        return count;
    }
    bool isBalanced(Node* root) {
        // code here
        if(root == nullptr)
            return true;
        int l = getH(root->left);
        int r = getH(root->right);
        if(abs(l-r)>1)return false;
        return isBalanced(root->left) && isBalanced(root->right);
    }
};