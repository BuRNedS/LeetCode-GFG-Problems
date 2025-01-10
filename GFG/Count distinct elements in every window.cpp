vector<int> countDistinct(vector<int> &arr, int k) {
        // code here.
        unordered_map<int,int>mp;
      int r=0;
        for(int i=0;i<k;i++){
            mp[arr[i]]++;
            
        }
        vector<int>ans;
        ans.push_back(mp.size());
        for(int i=k;i<arr.size();i++){
         mp[arr[r]]--;
         if(mp[arr[r]]==0)mp.erase(arr[r]);
          r++;
         mp[arr[i]]++;
         ans.push_back(mp.size());
        }
        return ans;
    }
