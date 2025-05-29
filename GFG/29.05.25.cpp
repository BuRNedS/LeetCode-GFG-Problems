class Solution {
  public:
    void h(Node* root, int cur, int len, int &max_, int &sum) {
        if(root==NULL)
            return;
        cur+=root->data;
        len++;
        if(root->left==NULL&&root->right==NULL) {
            if(len>max_) {
                max_=len;
                sum =cur;
            } else if(len == max_) 
                sum=max(sum, cur);
            return;
        }
        h(root->left,cur,len, max_,sum);
        h(root->right,cur, len,max_,sum);
    }

    int sumOfLongRootToLeafPath(Node *root) {
        int max_ =0;
        int sum=0;
        h(root,0,0, max_,sum);
        return sum;
    }
};
