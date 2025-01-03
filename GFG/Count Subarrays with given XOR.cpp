long subarrayXor(vector<int> &arr, int k) {
        int n=arr.size();
        map<int,int>mp;
        mp[0]=1;
        int xr=0;
        int ans=0;
        for(int i=0;i<n;i++){
            xr=xr^arr[i];
            ans+=mp[xr^k];
            mp[xr]++;
        }
        return ans;
    }
