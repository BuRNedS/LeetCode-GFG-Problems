Node *createTree(vector<int> parent) {
        // Your code here
        vector<Node*> nodes;
        for(int i=0; i<parent.size(); i++){
            nodes.push_back(new Node(i));
        }
        
        Node* root = NULL;
        for(int i=0; i<parent.size(); i++){
            if(parent[i] == -1){
                root = nodes[i];
            }
            else{
                if(!nodes[parent[i]]->left){
                    nodes[parent[i]]->left = nodes[i];
                }
                else{
                    nodes[parent[i]]->right = nodes[i];
                }
            }
        }
        
        return root;
    }
