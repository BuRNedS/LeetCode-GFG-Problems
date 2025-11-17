class Solution {
    int solve(vector<int> &arr, int n, int i, int prevInd, vector<vector<int>> &dp){
        if(i == n){
            return 0;
        }
        
        if(dp[i][prevInd+1] != -1){
            return dp[i][prevInd+1];
        }
        
        int incl=0, excl=0;
        if( prevInd == -1 || (arr[i] > arr[prevInd])){
            incl = arr[i] + solve(arr, n, i+1, i, dp);
        }
        
        excl = 0 + solve(arr, n, i+1, prevInd, dp);
        
        
        return dp[i][prevInd+1] =  max(incl, excl);
        
    }
    
    int solveTab(vector<int>& arr){
        int n = arr.size();
        // int prevInd=-1;
        // int sum=0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        
        for(int i=n-1 ; i>=0 ; i--){
            for(int prevInd=n-1 ; prevInd>=-1 ; prevInd--){
                int incl=0, excl=0;
                if( prevInd == -1 || (arr[i] > arr[prevInd])){
                    incl = arr[i] + dp[i+1][i+1];
                }
                
                excl = 0 + dp[i+1][prevInd+1];
                
                
                dp[i][prevInd+1] =  max(incl, excl);
                // cout<<dp[i][prevInd]<<endl;
            }
        }
        
        return dp[0][0];
        
        
    }
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        int n = arr.size();
        int prevInd=-1;
        int sum=0;
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(arr, n, 0, prevInd, dp);
        // return solveTab(arr);
    }
};
