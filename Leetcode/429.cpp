/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> t;
        if (root == nullptr) return t;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* temp = q.front();
                v.push_back(temp->val);
                q.pop();
                for(int j=0;j<temp->children.size();j++){
                    q.push(temp->children[j]);
                }
            }
            t.push_back(v);
        }
        return t;
    }
};