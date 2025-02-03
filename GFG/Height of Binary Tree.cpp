int height(Node* node) {
        if(node==NULL)
        return -1;
        int x=height(node->left);
        int y=height(node->right);
        return max(x,y)+1;
    }
