class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    vector<int> ans;
    
    void tree(Node *root){
        if(root == NULL){
            return;
        }
        ans.push_back(root->data);
        tree(root->left);
        tree(root->right);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        tree(root1);
        tree(root2);
        sort(ans.begin(), ans.end());
        return ans;
    }
};
