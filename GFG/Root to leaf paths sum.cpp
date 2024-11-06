class Solution {
public:
    int treePathsSum(Node *root) {
        return helper(root, 0);
    }
    
    int helper(Node* root, int currentSum) {
        if (!root) return 0;
        currentSum = currentSum * 10 + root->data;
        if (!root->left && !root->right) {
            return currentSum;
        }
        return helper(root->left, currentSum) + helper(root->right, currentSum);
    }
};
