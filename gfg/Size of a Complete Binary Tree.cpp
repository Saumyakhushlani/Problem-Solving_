class Solution {
  public:
    int countNodes(Node* root) {
        // code here
         if (root == nullptr)
            return 0;
        queue<Node*> q;
        int cnt = 0;
        q.push(root);
        bool f = false;
        while (!q.empty()) {
            Node* tmp = q.front();
            q.pop();
            if (tmp == nullptr) {
                f = true;
            } else {
                if (!f)
                    cnt++;
                q.push(tmp->left);
                q.push(tmp->right);
            }
        }
        return cnt;
    }
};