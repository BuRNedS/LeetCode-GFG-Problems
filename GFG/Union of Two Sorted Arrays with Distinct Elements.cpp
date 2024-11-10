vector<int> findUnion(vector<int> &a, vector<int> &b) {
       
       int n=a.size();
        int m=b.size();
        set<int>s;
        for(int i=0;i<n;i++)
        {
            s.insert(a[i]);
           
        }
        for(int i=0;i<m;i++)
        {
             s.insert(b[i]);
        }
        vector<int>ans(s.begin(),s.end());
        sort(ans.begin(),ans.end());
        return ans;
        
    }
