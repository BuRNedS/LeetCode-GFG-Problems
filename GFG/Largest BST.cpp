class Solution{
    public:
    int res = 1;
    vector<int> rec( Node* root ){
        vector<int> l = {1,0,INT_MIN,INT_MAX}, r = {1,0,INT_MIN,INT_MAX};
        if ( root->left ) l = rec(root->left);
        if ( root->right ) r = rec(root->right);
        if ( l[0] != -1 && r[0] != -1 && l[2] < root->data && r[3] > root->data ){
            res = max(res, l[1]+r[1]+1);
            if ( l[2] == INT_MIN && l[3] == INT_MAX ){
                l[2] = root->data; l[3] = root->data;
            }
            if ( r[2] == INT_MIN && r[3] == INT_MAX ){
                r[2] = root->data; r[3] = root->data;
            }
            return {1, l[1]+r[1]+1, max({root->data,l[2],l[3],r[2],r[3]}), 
                                min({root->data,l[2],l[3],r[2],r[3]})};
        } else return {-1, l[1]+r[1]+1, max({root->data,l[2],l[3],r[2],r[3]}), 
                                min({root->data,l[2],l[3],r[2],r[3]})};
    }
    int largestBst(Node *root){
        rec(root); return res;
    }
};
