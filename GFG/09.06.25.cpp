  bool help(Node* root, vector<int> & v){
        if(root==NULL)return false;
        v[root->data]=1;
        if(root->left==NULL && root->right==NULL){
            if((v[root->data-1]==1 && v[root->data+1]==1))return true;
        }
        return help(root->left,v)|| help(root->right,v);
    }
    bool isDeadEnd(Node *root) {
        // Code here
        vector<int> v(100001,0);
        v[0]=1;
        return help(root,v);
    }

