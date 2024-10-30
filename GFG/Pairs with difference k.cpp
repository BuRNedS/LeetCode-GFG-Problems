class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        // code here
        unordered_map<int,int>mp;
        int n = arr.size();
        int ans = 0;
        for(int  i = 0;i<n;i++) {
            ans+=mp[arr[i]+k];
            ans+=mp[arr[i]-k];
            mp[arr[i]]++;
        }
        return ans;
    }
};
