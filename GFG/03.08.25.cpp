class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        
        int n =mat.size();
        int m =mat[0].size();
        vector<vector<int>> temp(n,vector<int> (m+1,0));
        for(auto a: opr){
            int val = a[0];
            int x1 = a[1];
            int y1 = a[2];
            int x2 = a[3];
            int y2 = a[4];
            for(int k = x1;k<= x2;k++){
                temp[k][y1]+=val;
                temp[k][y2+1]-=val;
            }
        }
        for(int i =0;i< n;i++){
            for(int j =0;j<= m;j++){
                temp[i][j]+=temp[i][j-1];
            }
        }
        for(int i =0;i< n;i++){
            for(int j =0;j< m;j++){
                mat[i][j]+=temp[i][j];
            }
        }
        return mat;
    }
};

