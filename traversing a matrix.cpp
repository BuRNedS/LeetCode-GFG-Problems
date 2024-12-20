vector<int> spirallyTraverse(vector<vector<int> > &mat) {
        // code here
        int row=0,col=0,srow=0,scol=0,erow = mat.size() - 1, ecol = mat[0].size() - 1; // End row and column
        vector<int>ans;
       while (srow <= erow && scol <= ecol) {
            for(int j=scol;j<=ecol;j++){
                ans.push_back(mat[srow][j]);
            }
            srow++;
            for(int j=srow;j<=erow;j++){
                ans.push_back(mat[j][ecol]);
            }
            ecol--;
               if (srow <= erow) {
            for(int j=ecol;j>=scol;j--){
                ans.push_back(mat[erow][j]);
            }
            erow--;
               }
                 if (scol <= ecol) {
            
              for(int j=erow;j>=srow;j--){
                ans.push_back(mat[j][scol]);
            }
            scol++;
                 }
            
        }
        return ans;
        
    }
