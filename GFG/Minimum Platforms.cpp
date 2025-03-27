int findPlatform(vector<int>& arr, vector<int>& dep) {
        map<int, int> mp;
        
        for(auto it : arr){
            mp[it]++;
        }
        
        for(auto it : dep){
            mp[it+1]--;
        }
        
        int maxi = 1;
        int cnt=0;
        for(auto it : mp){
            // cout<<it.first<<endl;
            cnt += it.second;
            maxi = max(maxi, cnt);
        }
        
        return maxi;
    }

