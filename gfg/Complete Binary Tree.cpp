class Solution {
  public:
    bool isCompleteBT(Node* root) {
        // code here
        if (root == nullptr)
            return true;
        queue<Node*> q;
        q.push(root);
        bool f = false;
        while (!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            if (tmp == nullptr)
                f = true;
            else {
                if (f)
                    return false;
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return true;
    }
};