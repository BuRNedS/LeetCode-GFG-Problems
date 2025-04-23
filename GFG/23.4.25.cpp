 vector<int> singleNum(vector<int>& arr) {
        // Code here.
        vector<int> ans;
        unordered_map<int,int> mp;
        for(auto it:arr)
        {
            mp[it]+=1;
        }
        for(auto it:mp)
        {
            if(it.second==1)
            ans.push_back(it.first);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }

