private:
    int solve(vector<int> &cost, int i, int n, vector<int> &dp){
        if(i==n-1){
            return cost[n-1];
        }
        if(i== n-2){
            return  cost[n-2];
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        dp[i]= cost[i] +min(solve(cost, i+1, n, dp), solve(cost, i+2, n, dp));
        return dp[i];
    }
  public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int i=0;
        vector<int> dp(n+1, -1);
        
        int maxi= min(solve(cost, i, n, dp), solve(cost, i+1, n, dp));
        return maxi;
    }
