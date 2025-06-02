 int n=grid.size(),m=grid[0].size();
        
             vector<vector<int>> dp(n, vector<int>(m, 0));
if (grid[0][0] == 1 || grid[n - 1][m - 1] == 1) return 0;

// First row
for (int i = 0; i < m; i++) {
    if (grid[0][i] == 0) dp[0][i] = 1;
    else break;
}

// First column
for (int i = 0; i < n; i++) {
    if (grid[i][0] == 0) dp[i][0] = 1;
    else break;
}
 
 for(int i=1;i<n;i++)
 {
     for(int j=1;j<m;j++)
     {
         if(grid[i][j])continue;
           
             dp[i][j]=dp[i-1][j]+dp[i][j-1];
        
     }
 }
   return dp[n-1][m-1];
