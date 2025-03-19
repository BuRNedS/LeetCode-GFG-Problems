
int helper(int idx, vector<int>& prices, int k, bool canBuy,  vector<vector<vector<int>>> &dp)
    {
        if(idx >= prices.size() || k <= 0)
            return 0;
        int pick = INT_MIN, notPick = INT_MIN;
        if(dp[idx][k][canBuy] != -1)
            return dp[idx][k][canBuy];
        if(canBuy)
        {
            pick = -prices[idx] + helper(idx+1, prices, k, false, dp);
            notPick  = helper(idx+1, prices, k, canBuy,dp);
        }
        else
        {
            pick = prices[idx] + helper(idx+1, prices, k-1, true, dp);
            notPick  = helper(idx+1, prices, k, canBuy,dp);
        }
        return dp[idx][k][canBuy] = max(pick,notPick);
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return helper(0,prices,k,true,dp);
    }
