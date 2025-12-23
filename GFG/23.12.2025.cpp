class Solution {
  public:
    vector<int> cntInRange(vector<int> &arr, vector<vector<int>> &queries) {
        // code here
        vector<int>ans;
        
        sort(arr.begin(), arr.end());
        
        for (auto i:queries) {
            int a = i[0];
            int b = i[1];
            
            auto start = std::lower_bound(arr.begin(), arr.end(), a);
            auto end = std::upper_bound(arr.begin(), arr.end(), b);
            
            ans.push_back((int)(end-start));
        }
        
        return ans;
    }
};
