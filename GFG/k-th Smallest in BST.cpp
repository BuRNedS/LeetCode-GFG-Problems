class Solution {
  public:
  int ans=-1;
  void Solve(Node* root, int &k){
      if(root==NULL)
      return;
     else{
      Solve(root->left,k);
      k--;
      if(k==0){
      ans=root->data;
          return;
      }
      Solve(root->right,k);
     }
  }
    // Return the Kth smallest element in the given BST
    int kthSmallest(Node *root, int k) {
        Solve(root,k);
        return ans;
    }
};
