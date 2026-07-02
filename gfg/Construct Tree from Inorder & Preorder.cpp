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
    unordered_map<int,int>in;
    int idx=0;
    Node* solve(vector<int>& preorder,int low,int high){
        if(low>high)return nullptr;
        Node* node = new Node(preorder[idx]);
        int id = in[preorder[idx]];
        idx++;
        node->left=solve(preorder,low,id-1);
        node->right=solve(preorder,id+1,high);
        return node;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }
        return solve(preorder,0,inorder.size()-1);
    }
};