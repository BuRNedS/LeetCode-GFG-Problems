class Solution {
  private:
    int check(string &s1, string &s2, string &s, int ind1, int ind2, int ind, int n1, int n2, int n, vector<vector<int>>&dp){
        if(ind == n) return 1;
        if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
        if(ind1 == n1){
            for(int k = ind2; k < n2; ++k){
                if(s2[k] != s[ind++]) return dp[ind1][ind2] = 0;
            }
            return dp[ind1][ind2] = 1;
        }
        if(ind2 == n2){
            for(int k = ind1; k < n1; ++k){
                if(s1[k] != s[ind++]) return dp[ind1][ind2] = 0;
            }
            return dp[ind1][ind2] = 1;
        }
        if(s1[ind1] != s[ind] && s2[ind2] != s[ind]){
            return dp[ind1][ind2] = 0;
        }

        int first = 0;
        int second = 0;

        if(s1[ind1] == s[ind]) {
            first = check(s1, s2, s, ind1 + 1, ind2, ind + 1, n1, n2, n, dp);
        }
        if(s2[ind2] == s[ind]) {
            second = check(s1, s2, s, ind1, ind2 + 1, ind + 1, n1, n2, n, dp);
        }

        return dp[ind1][ind2] = max(first, second);
    }

  public:
    bool isInterleave(string &s1, string &s2, string &s3) {
        int n1 = s1.size();
        int n2 = s2.size();
        int n = s3.size();
        if(n1 + n2 != n) return false;
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -1));

        int ans = check(s1, s2, s3, 0, 0, 0, n1, n2, n, dp);
        return ans == 1;
    }
};
