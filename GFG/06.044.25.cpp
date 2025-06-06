class Solution {
  public:
    int mod=1e5+7;

    vector<int> search(string &pat, string &txt) {
        vector<int>ans;
        int a=0,b=0;
        int n=txt.size(),m =pat.size();
        if(m>n) return ans;
        for(int i= 0; i <m;i++) {
            a=(a+(txt[i] -'a'+1))%mod;
            b=(b+(pat[i] -'a'+1))%mod;
        }
        if(a==b && txt.substr(0,m)==pat)
            ans.push_back(1);
        for(int i= m,j =0; i<n;i++,j++){
            a=(a-(txt[j]-'a'+1) +mod)%mod;  
            a=(a+(txt[i]-'a'+1))%mod;       
            if(a==b && txt.substr(j +1,m)==pat)
                ans.push_back(j+2); 
        }
        return ans;
    }
};
