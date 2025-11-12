class Solution {
    vector<vector<int>> dp;
  public:
  Solution():dp(101, vector<int>(100, -1)){}
    bool wildCard(string &txt, string &pat, int i=0, int j=0) {
        if(i == txt.size() && j == pat.size()) return true;
        if(j == pat.size()) return false;
        if(dp[i][j] != -1) return dp[i][j];
        
        bool ans = false;
        if(i == txt.size())
            ans = pat[j] == '*' && wildCard(txt, pat, i, j+1);
        else if(pat[j] == '*')
            ans = wildCard(txt, pat, i, j+1) || wildCard(txt, pat, i+1, j);
        else if(pat[j] == '?' || pat[j] == txt[i])
            ans = wildCard(txt, pat, i+1, j+1);
            
        return dp[i][j] = ans;
    }
};
