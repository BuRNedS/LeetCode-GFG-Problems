class Solution {
  public:
    int memo(int n, vector<int> &dp){
        if(n == 0){
            return 0;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        
        int min_cnt = INT_MAX;
        for(int i = 1;i*i<=n;i++){
            int cnt = memo(n-i*i, dp);
            if(cnt<min_cnt)min_cnt = cnt;
        }
        
        return dp[n] = min_cnt+1;
    }
    int tabu(int n){
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int k = 1;k<=n;k++){
            for(int i = 1; i*i<=k;i++){
                dp[k] = min(dp[k], dp[k-i*i]+1);
            }
        }
        return dp[n];
    }
    int minSquares(int n) {
        // memoisation method
        vector<int> dp(n+1, -1);
        return memo(n, dp);
        
        // tabulation method
        // return tabu(n);
    }
};
