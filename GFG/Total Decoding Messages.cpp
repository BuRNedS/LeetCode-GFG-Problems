class Solution {
  public:
    int countWays(string &s) {
        // Code here
        int mod = 1e9 + 7, n = s.size();
		    int prev1 = 1, prev2 = 1;
		    for(int i = 2; i <= n; i++) {
		        int curr = 0;
		        if(s[i - 1] != '0') 
		            curr = prev1;
		        if((s[i - 2] == '1') || (s[i - 2] == '2' && s[i - 1] <= '6'))
		            curr = (curr + prev2) % mod;
		        prev2 = prev1;
		        prev1 = curr;
		    }
		    return prev1;
    }
};
