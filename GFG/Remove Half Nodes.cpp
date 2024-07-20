Node *RemoveHalfNodes(Node *root) {
    if (root == nullptr) return nullptr;
    
    root->left = RemoveHalfNodes(root->left);
    root->right = RemoveHalfNodes(root->right);
    
    if (root->left and !root->right) return root->left;
    else if (root->right and !root->left) return root->right;
    else return root;
}
