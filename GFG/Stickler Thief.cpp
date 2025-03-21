class Solution {
  public:
  int find(vector<int>&arr,int i,vector<int>& dp){
      if(i==0) return 0;
      if(dp[i]!=-1) return dp[i];
      int loot=arr[i-1]+find(arr,i-2,dp);
      int dontloot=find(arr,i-1,dp);
      return dp[i]=max(loot,dontloot);
  }
  int find(vector<int>&arr){
      int n=arr.size();
      vector<int>dp(n+1);
      for(int i=1;i<n+1;i++){
          int loot=arr[i-1];
          int dontloot=dp[i-1];
          if(i>=2) loot+=dp[i-2];
          dp[i]=max(loot,dontloot);
      }
      return dp[n];
  }
  int findOpti(vector<int>& arr){
      int n=arr.size();
      int pre1=0,pre2=0;
      for(int i=1;i<n+1;i++){
          int loot=arr[i-1];
          int dontloot=pre1;
          if(i>=2) loot+=pre2;
          pre2=pre1;
          pre1=max(loot,dontloot);
      }
      return pre1;
  }
    int findMaxSum(vector<int>& arr) {
        // code here
        // int n=arr.size();
        // vector<int>dp(n+1,-1);
        // return find(arr,n,dp);
        // return find(arr);
        return findOpti(arr);
    }
};
