/*
Node is as follows
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int data) {
        data = data;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node* getsmall(Node* root,stack<Node*> &asc){
        if(asc.empty())return nullptr;
        Node* small=asc.top();
        asc.pop();
        Node* right = small->right;
        while(right){
            asc.push(right);
            right=right->left;
        }
        return small;
    }
    Node* getlarger(Node* root,stack<Node*> &desc){
        if(desc.empty())return nullptr;
        Node *big = desc.top();
        desc.pop();
        Node *left= big->left;
        while(left){
            desc.push(left);
            left=left->right;
        }
        return big;
    }
    bool findTarget(Node *root, int k) {
        // your code here.
        Node* t= root;
        stack<Node*>asc;
        stack<Node*>desc;
        while(t){
            asc.push(t);
            t=t->left;
        }
        t=root;
        while(t){
            desc.push(t);
            t=t->right;
        }
        Node *i = getsmall(root,asc);
        Node *j = getlarger(root,desc);
        while(i && j && i!=j && i->data<=j->data){
            int sum = i->data+j->data;
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