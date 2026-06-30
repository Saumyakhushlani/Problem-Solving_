/* The Node structure is
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */
class Solution {
  public:
    int minDepth(Node *root) {
        // code here
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
                if(!curr->left && !curr->right)
                    return count;
                
            }
        }
        return count;
    }
};