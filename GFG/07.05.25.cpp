class Solution {
  public:
    void dfs(Node* root, vector<vector<int>>& ans, vector<int>& path){
        if(!root->left && !root->right){
            path.push_back(root->data);
            ans.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(root->data);
        if(root->left){
            dfs(root->left,ans,path);
        }
        if(root->right){
            dfs(root->right,ans,path);
        }
        path.pop_back();
    }
    vector<vector<int>> Paths(Node* root) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(root,ans,path);
        return ans;
    }
};
