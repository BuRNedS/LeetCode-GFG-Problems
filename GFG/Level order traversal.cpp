vector<vector<int>> levelOrder(Node *root) {
        // Your code here
        vector<vector<int>> levelOrderStorage;
        
        queue<Node*> q;
        q.push(root);
        
        while(!q.empty()){
            int n = q.size();
            vector<int> temp;
            while(n--){
                Node* topEle = q.front();
                q.pop();
                
                temp.push_back(topEle->data);
                if(topEle->left)    
                    q.push(topEle->left);
                if(topEle->right)
                    q.push(topEle->right);    
            }
            levelOrderStorage.push_back(temp);
        }
        
        return levelOrderStorage;
    }
