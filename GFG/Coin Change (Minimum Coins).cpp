 int func(int i, vector<int>&coins,int sum,vector<vector<int>>&dp){
        
        //base case
        if(i==0){
            if(sum%coins[0] == 0)return sum/coins[0];
            else return INT_MAX;
        }
        
        if(dp[i][sum] != -1)return dp[i][sum];
        
        int ntake = func(i-1,coins,sum,dp);
        int take = INT_MAX;
        if(sum>=coins[i]){
            take  = func(i,coins,sum-coins[i],dp);
            if(take != INT_MAX){
                take += 1;
            }
        }
        
        return dp[i][sum] = min(take,ntake);
    }
    int minCoins(vector<int> &coins, int sum) {
        // code here
        int n = coins.size();
        vector<vector<int>>dp(n+1,vector<int>(sum+1,-1));
        return (func(n-1, coins, sum,dp) == INT_MAX) ? -1 : func(n-1, coins, sum,dp);
    }
