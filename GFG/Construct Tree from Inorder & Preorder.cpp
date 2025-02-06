class Solution {
    int get_index(vector<int> &inorder,int val, int end ,int st){
        for(int i = st; i <= end ; i++){
            if(inorder[i] == val) return i;
        }
        return 0;
    }
    
    Node * build(vector<int> &inorder, vector<int> &preorder,int st,int end,int &idx,int n){
        if( idx >= n || st > end) return  NULL;
         
        int index = get_index(inorder,preorder[idx], end ,st);
        Node* root = new Node(inorder[index]);
        idx++;
        root->left = build(inorder,preorder,st,index-1,idx,n);
        root->right = build(inorder,preorder,index+1,end,idx,n);
        return root;
    }
  public:
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        int idx = 0;
        Node * root = build(inorder,preorder,0,inorder.size()-1,idx,inorder.size());
        return root;
    }
};
