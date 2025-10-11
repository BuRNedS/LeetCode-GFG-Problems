class Solution {
  public:
    int solve(Node* root, int &maxSum) {
        if (root == NULL)
            return 0;

        // Recursively find max sum on left and right
        int left = max(0, solve(root->left, maxSum));  // Ignore negative sums
        int right = max(0, solve(root->right, maxSum));

        // Calculate max path passing through this node
        int currPathSum = root->data + left + right;

        // Update global maximum
        maxSum = max(maxSum, currPathSum);

        // Return max gain for parent recursion
        return root->data + max(left, right);
    }

    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }
};
