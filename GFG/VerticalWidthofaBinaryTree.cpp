class Solution {
  public:
    void solve(Node* root, unordered_map<int, int> &mp, int width){
        if(!root) return ;
        
        mp[width]++;
        
        solve(root->left, mp, width-1);
        solve(root->right, mp, width+1);
    }
    // Function to find the vertical width of a Binary Tree.
    int verticalWidth(Node* root) {
        // code here
        unordered_map<int, int> mp;
        
        solve(root, mp, 0);
        return mp.size();
        
    }
};
