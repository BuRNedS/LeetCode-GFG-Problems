bool solve(Node* node, int l, int r){
        if(!node)
        return true;
        
        if(node->data<=l || node->data>=r)
        return false;
        
        int rl = solve(node->left, l, node->data);
        int rr = solve(node->right, node->data, r);
        
        return rl && rr;
    }
    bool isBST(Node* root) {
        
       return solve(root, -1e9, 1e9);
    }
