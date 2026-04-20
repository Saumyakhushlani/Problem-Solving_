class Solution {
    int count = 0;

public:
    pair<int,int> avg(TreeNode* root) {
        if (root == nullptr) return {0, 0};

        auto left = avg(root->left);
        auto right = avg(root->right);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        if (sum / cnt == root->val) count++;

        return {sum, cnt};
    }

    int averageOfSubtree(TreeNode* root) {
        avg(root);
        return count;
    }
};