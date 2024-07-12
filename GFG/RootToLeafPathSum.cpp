class Solution {
  public:
    bool hasPathSum(Node *root, int target) {
        if(root==0) return false;
        if(root->left==0 && root->right==0) {
            return root->data==target;
        }
        return hasPathSum(root->left, target-root->data) || hasPathSum(root->right, target-root->data);
    }
};
