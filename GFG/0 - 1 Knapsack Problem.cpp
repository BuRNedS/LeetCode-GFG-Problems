class Solution {
  public:
  int solve(int w,vector<int>&wt,vector<int>&val,int idx,vector<vector<int>>&dp){
      
      if(idx>=wt.size())
      return 0;
      if(dp[w][idx]!=-1)
      return dp[w][idx];
      int ans=0;
      if(w-wt[idx]>=0)
      ans=max(ans,val[idx]+solve(w-wt[idx],wt,val,idx+1,dp));
      ans=max(ans,solve(w,wt,val,idx+1,dp));
      
      return dp[w][idx]=ans;
      
  }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n=wt.size();
        vector<vector<int>>dp(W+1,vector<int>(n,-1));
        return solve(W,wt,val,0,dp);
    }
};

