class Solution {
  private:
    Node * create(int s,int e,vector<int> & nums){
        if(e<s) return NULL;
        int mid = (s+e)/2;
        Node * root = new Node(mid);
        root->left = create(s,mid-1,nums);
        root->right = create(mid+1,e,nums);
        return root;
    }
  public:
    Node* sortedArrayToBST(vector<int>& nums) {
        return create(0,nums.size()-1,nums);
    }
};
