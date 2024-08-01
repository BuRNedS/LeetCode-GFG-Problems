    vector<int> spirallyTraverse(vector<vector<int> > &m) {
        int u=0,d=m.size()-1,l=0,r=m[0].size()-1;
        bool H=true,F=true;
        vector<int> ans;
        while(u<=d && l<=r)
        {
            if(H)
            {
                if(F)
                {
                    // going right
                    for(int i=l;i<=r;i++) ans.push_back(m[u][i]);
                    u++;
                    H=false;
                }
                else
                {
                    // going left
                    for(int i=r;i>=l;i--) ans.push_back(m[d][i]);
                    d--;
                    H=false;
                }
            }
            else
            {
                if(F)
                {
                    // goin down
                    for(int i=u;i<=d;i++) ans.push_back(m[i][r]);
                    r--;
                    H=true;
                    F=false;
                }
                else
                {
                    // going up
                    for(int i=d;i>=u;i--) ans.push_back(m[i][l]);
                    l++;
                    H=true;
                    F=true;
                }
            }
            
        }
        
        // for(auto &x:ans) cout<<x<<" ";
        
        return ans;
    }
