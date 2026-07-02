/* Node Structure
class Node {
  public:
    int data;
    Node* left;
    Node* right;
    Node(int x) {
        data = x;
        left = right = nullptr;
    }
}; */

class Solution {
  public:
    unordered_map<int,int>in;
    int idx=0;
    Node* solve(vector<int>& post,int low,int high){
        if(low>high)return nullptr;
        Node* node = new Node(post[idx]);
        int id = in[post[idx]];
        idx--;
        node->right=solve(post,id+1,high);
        node->left=solve(post,low,id-1);
        return node;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &postorder) {
        // code here
        for(int i=0;i<inorder.size();i++){
            in[inorder[i]]=i;
        }
        idx=postorder.size()-1;
        return solve(postorder,0,inorder.size()-1);
    }
};