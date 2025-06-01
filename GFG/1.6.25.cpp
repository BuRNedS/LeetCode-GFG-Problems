bool check(vector<vector<int>> &matrix,int n){
        int rows = matrix.size();
        int cols = matrix[0].size();
        int s = 0;
        int e = rows*cols - 1;
        int m ;
        while(s<=e){
            m = s + (e-s)/2;
            int rowindex = m/cols;
            int colindex = m%cols;
            if(matrix[rowindex][colindex]==n){
                return true;
            }
            else if (matrix[rowindex][colindex]>n){
                e=m-1;
            }
            else{
                s=m+1;
            }
        }
        return false;
    }
    int countPairs(vector<vector<int>> &mat1, vector<vector<int>> &mat2, int x) {
        int ans =0;
        for(int i =0;i<mat1.size();i++){
            for(int j=0;j<mat1[i].size();j++){
                if(check(mat2,x - mat1[i][j])) ans++;
            }
        }
        return ans;
    }
