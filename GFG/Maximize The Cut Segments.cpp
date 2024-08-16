class Solution {
public:
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        vector<int> val = {x, y, z};
        vector<int> dp(n + 1, -1); 
        dp[0] = 0; 
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (i >= val[j] && dp[i - val[j]] != -1) {
                    dp[i] = max(dp[i], dp[i - val[j]] + 1);
                }
            }
        }
        
        return dp[n] == -1 ? 0 : dp[n];
    }
};
