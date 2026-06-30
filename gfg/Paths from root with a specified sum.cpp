/* A Tree node
class Node {
public:
    int key;
    Node *left, *right;
    Node(int x) {
        left = right = nullptr;
        key = x;
    }
};*/

class Solution {
  public:
    void solve(Node* root, int k,int sum,vector<vector<int>> &res,vector<int> &v){
        if(root==nullptr) return;
        
        sum+=root->key;
        v.push_back(root->key);
        if(sum==k)res.push_back(v);
        solve(root->left,k,sum,res,v);
        solve(root->right,k,sum,res,v);
        v.pop_back();
        return;
    }
    vector<vector<int>> printPaths(Node *root, int sum) {
        // code here
        vector<vector<int>> res;
        vector<int>v;
        solve(root,sum,0,res,v);
        return res;
    }
};