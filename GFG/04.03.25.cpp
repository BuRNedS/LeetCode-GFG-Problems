
class Solution {
  public:
    int dp[1005];
    int fn(vector<int>&a, int i){
        if(i>=a.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ans=1;
        for(int j=i;j<a.size();j++){
            if(a[j]>a[i])ans=max(ans,fn(a,j)+1);
        }
        return dp[i]=ans;
    }
    int lis(vector<int>& a) {
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<a.size();i++){
            ans=max(ans,fn(a,i));
        }
        return ans;
    }
};
