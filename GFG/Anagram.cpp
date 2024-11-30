bool areAnagrams(string& s1, string& s2) {

       int n=s1.size();
       int m=s2.size();
       if(m!=n) return false;
       vector<int>a1(26,0);
       vector<int>a2(26,0);
       for(int i=0;i<n;i++)
       {
           int idx=s1[i]-'a';
           a1[idx]++;
           int idy=s2[i]-'a';
           a2[idy]++;
       }
       return a1==a2;
    }
