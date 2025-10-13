class Solution {
  public:
    pair<int, int> helper(Node* root) {
        if (!root) return {0, 0};

        auto left = helper(root->left);
        auto right = helper(root->right);

        // include current node (cannot include its children)
        int include = root->data + left.second + right.second;

        // exclude current node (can include or exclude its children)
        int exclude = max(left.first, left.second) + max(right.first, right.second);

        return {include, exclude};
    }

    int getMaxSum(Node *root) {
        auto ans = helper(root);
        return max(ans.first, ans.second);
    }
};
