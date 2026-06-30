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
    TreeNode* getsmall(TreeNode* root,stack<TreeNode*> &asc){
        if(asc.empty())return nullptr;
        TreeNode* small=asc.top();
        asc.pop();
        TreeNode* right = small->right;
        while(right){
            asc.push(right);
            right=right->left;
        }
        return small;
    }
    TreeNode* getlarger(TreeNode* root,stack<TreeNode*> &desc){
        if(desc.empty())return nullptr;
        TreeNode *big = desc.top();
        desc.pop();
        TreeNode *left= big->left;
        while(left){
            desc.push(left);
            left=left->right;
        }
        return big;
    }
    bool findTarget(TreeNode* root, int k) {
        TreeNode* t= root;
        stack<TreeNode*>asc;
        stack<TreeNode*>desc;
        while(t){
            asc.push(t);
            t=t->left;
        }
        t=root;
        while(t){
            desc.push(t);
            t=t->right;
        }
        TreeNode *i = getsmall(root,asc);
        TreeNode *j = getlarger(root,desc);
        while(i && j && i!=j && i->val<=j->val){
            int sum = i->val+j->val;
            if(sum==k){
                return true;
            }
            if(sum>k){
                j=getlarger(root,desc);
            }else{
                i=getsmall(root,asc);
            }
        }
        return false;
    }
};