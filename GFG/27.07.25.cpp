void setMatrixZeroes(vector<vector<int>> &mat) {
    // code here
    int n = mat.size();
    int m = mat[0].size();
    int cz = 0, rz = 0;
    for(int i = 0; i < n; i++) if(mat[i][0] == 0) cz = 1;
    for(int j = 0; j < m; j++) if(mat[0][j] == 0) rz = 1;
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++) {
            if(mat[i][j] == 0) {
                mat[0][j] = 0;
                mat[i][0] = 0;
            }
        }    
    }
    
    for(int i = 1; i < n; i++) {
        for(int j = 1; j < m; j++){
            if(mat[i][0] == 0 || mat[0][j] == 0)
                mat[i][j] = 0;
        }
    }
    
    if(cz) for(int i = 0; i < n; i++) mat[i][0] = 0;
    if(rz) for(int j = 0; j < m; j++) mat[0][j] = 0;
}
