class Solution {
    int n , m ; 
    int f(vector<vector<int>> & grid , vector<vector<int>> & dp , int i , int j){
        if(i >= n || j < 0 || j >= m || i < 0){
            return 0 ; 
        }
        if(dp[i][j] != -1) return dp[i][j] ; 
        return dp[i][j] = grid[i][j] + max({f(grid, dp , i+1 , j+1), f(grid , dp , i , j+1) , f(grid , dp , i-1 , j+1)});
    }
  public:
    int maxGold(vector<vector<int>>& mat) {
        n = mat.size() , m = mat[0].size() ; 
        int res = 0 ; 
        vector<vector<int>> dp(n+1, vector<int>(m+1 , -1)) ; 
        for(int i = 0 ; i < n ; i++){
            res = max(res , f(mat ,dp , i , 0)) ; 
        }
        return res; 
    }
};
