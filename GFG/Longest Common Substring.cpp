class Solution {
  public:
    int solve(string& str1,string &str2,int last1,int last2,vector<vector<int>>&dp){
        if(last1 < 0 || last2 < 0){
            return 0;
        }
        
        if(dp[last1][last2]!=-1){
            return dp[last1][last2];
        }
        
        if(str1[last1] == str2[last2]){
            return dp[last1][last2] = 1 + solve(str1,str2,last1-1,last2-1,dp);
        }
        
        return 0;
    }
    int longestCommonSubstr(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans,solve(str1,str2,i,j,dp));
            }
        }
        
        return ans;
    }
};
