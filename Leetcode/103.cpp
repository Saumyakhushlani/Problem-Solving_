/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> t;
        if (root == nullptr) return t;
        queue<TreeNode*> q;
        q.push(root);
        int k =0;
        while (!q.empty()) {
            vector<int> v;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                TreeNode* temp = q.front();
                v.push_back(temp->val);
                if (temp->left != nullptr)
                    q.push(temp->left);

                if (temp->right != nullptr)
                    q.push(temp->right);
                q.pop();
            }
            if(k==0){
                t.push_back(v);
                k=1;
            }else{
                reverse(v.begin(), v.end());
                t.push_back(v);
                k=0;
            }
        }
        return t;
        
    }
};