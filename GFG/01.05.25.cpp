vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> pascal;
        for(int i = 0; i<n;i++){
            vector<int> temp(i+1,1);
            pascal.push_back(temp);
        }
        for(int i = 2; i< n;i++){
            for(int j = 1; j < i;j++)
                pascal[i][j] = pascal[i-1][j-1]+pascal[i-1][j];
        }
        return pascal[n-1];
    }
