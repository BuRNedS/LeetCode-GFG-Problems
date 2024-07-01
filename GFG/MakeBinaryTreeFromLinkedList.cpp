class Solution {
  public:
    TreeNode* maketree(Node *&head,TreeNode *&root){
      if(!head){
          return NULL;
      }
      int val=head->data;
      head=head->next;
      TreeNode *temp=new TreeNode(val);
      temp->left=maketree(head,root);
      temp->right=maketree(head,root);
      root=temp;
      return root;
  }
    void convert(Node *head, TreeNode *&root) {
        root=maketree(head,root);
        return;
   }
};
