class Solution {
  public:
    int height(Node * root,int& maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        
        int left = height(root->left,maxi);
        int right = height(root->right,maxi);
        maxi= max(maxi,left+right);
        return max(left,right)+1; //height is returned here
    }
    int diameter(Node* root) {
        // Your code here
        int maxi= INT_MIN;
        height(root,maxi);
        return maxi;
    }
};
