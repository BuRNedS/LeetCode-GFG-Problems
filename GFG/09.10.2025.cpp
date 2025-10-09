class Solution {
  public:
    void traverse(Node* root, vector<int>& ans) {
        if (root == NULL) return;

        // 1. Visit left subtree
        traverse(root->left, ans);
        // 2. Visit right subtree
        traverse(root->right, ans);
        // 3. Visit the node itself
        ans.push_back(root->data);
    }

    vector<int> postOrder(Node* root) {
        vector<int> ans;
        traverse(root, ans);
        return ans;
    }
};
