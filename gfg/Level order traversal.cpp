/* A binary tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/

class Solution {
  public:
    vector<int> levelOrder(Node *root) {
        // code here
        vector<int>ans;
        if (root == nullptr)
            return ans;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                Node* curr = q.front();
                q.pop();

                ans.push_back(curr->data);

                if (curr->left)
                    q.push(curr->left);

                if (curr->right)
                    q.push(curr->right);
            }
        }

        return ans;
    }
};