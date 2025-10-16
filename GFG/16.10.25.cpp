class Solution {
  public:
  
    Node* helper(Node* root,int l,int r){
        if(!root) return nullptr;
        
        int val=root->data;
        if(val<l) return helper(root->right,l,r);
        else if(val>r) return helper(root->left,l,r);
        
        Node* newNode=new Node(val);
        newNode->left=helper(root->left,l,r);
        newNode->right=helper(root->right,l,r);
        
        return newNode;
    }
  
    Node* removekeys(Node* root, int l, int r) {
        // code here
        return helper(root,l,r);
    }
};
