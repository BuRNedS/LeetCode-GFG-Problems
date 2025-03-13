int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n+1, vector<int>(W+1, 0));
        for(int i=1; i<=n; i++){
            for(int w=0; w<=W; w++){
                int ntake=dp[i-1][w];
                int take=-1e9;
                if(wt[i-1]<=w) take=val[i-1]+dp[i-1][w-wt[i-1]];
                dp[i][w]=max(take, ntake);
            }
        }
        return dp[n][W];
    }
