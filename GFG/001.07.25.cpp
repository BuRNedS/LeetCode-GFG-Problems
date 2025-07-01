class Solution {
  public:
    int count(vector<int>& freq){
        int ans = 0;
        for(auto i : freq){
            if(i!=0) ans++;
        }
        return ans;
    }
    int substrCount(string &s, int k) {
        vector<int>freq(26,0);
        
        int ans = 0;
        int i = 0;
        int j = 0;
        
        while(j<s.size()){
            freq[s[j]-'a']++;
            
            if(j-k+1>i) freq[s[i++]-'a']--;
            
            if(j-k+1==i && count(freq)==k-1) ans++;
            
            j++;
        }
        return ans;
    }
};
