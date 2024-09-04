class Solution {
    Integer dp[];
    public int dfs(int n,int index)
    {
        if(index>n) return 0;
        if(index==n) return 1;
        if(dp[index]!=null)return dp[index];
        return dp[index]=1+Math.min(dfs(n,index+1),dfs(n,index+2));
    }
    public int nthStair(int n) {
        // Code here
        dp=new Integer[n+1];
        return dfs(n,0);
    }
}
