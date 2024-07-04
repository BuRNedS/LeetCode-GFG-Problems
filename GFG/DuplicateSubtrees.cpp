string helper(Node *root, vector<Node*> &ans, 
                unordered_map<string,int> &mp)
    {
        string temp = "";
        if(root == NULL)
            return "#";
        temp += to_string(root->data);
        temp += helper(root->left,ans,mp);
        temp += helper(root->right,ans,mp);
        if(mp[temp] == 1)
            ans.push_back(root);
        mp[temp]++;
        return temp;
        
    }
    vector<Node*> printAllDups(Node* root) 
    {
        vector<Node*> ans;
        unordered_map<string,int> mp;
        helper(root,ans,mp);
        return ans;
        // Code here
    }
