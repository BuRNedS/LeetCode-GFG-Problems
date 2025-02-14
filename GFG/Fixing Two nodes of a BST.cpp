class Solution {
    void inorderTraversal(Node* root,vector<Node*> &vec){
        if(!root) return ;
        inorderTraversal(root->left,vec);
        vec.push_back(root);
        inorderTraversal(root->right,vec);
    }
  public:
    void correctBST(Node* root) {
         vector<Node*> vec;
         inorderTraversal(root,vec);
         int i = 0;
         int n = vec.size();
         int j = n-1;
         
          while( i+1 < n){
              if(vec[i]->data > vec[i+1]->data){
                 break; 
              }
              i++;
          }
          while( 0 <= j-1){
              if(vec[j-1]->data > vec[j]->data){
                 break; 
              }
              j--;
          }
          swap(vec[i]->data,vec[j]->data);
          return ;
    }
};
