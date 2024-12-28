class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        // Code here
        unordered_map<int,vector<pair<int,int>>> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                mp[arr[i]+arr[j]].push_back({i,j});
            }
        }
        vector<vector<int>> ans;
        for(int i=2;i<n;i++){
            int rem=-arr[i];
            if(mp.find(rem)!=mp.end()){
                for(auto j: mp[rem]){
                    if(j.second<i){
                        ans.push_back({j.first,j.second,i});
                    }
                }
            }
        }
        return ans;
    }
};
