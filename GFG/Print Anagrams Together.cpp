class Solution {
  public:
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> map;
        
        for (int i= 0; i < arr.size(); i++ ) {
            string temp = arr[i];
            sort(temp.begin(), temp.end());
            map[temp].push_back(arr[i]);
            
        }
        
        for (auto it : map) {
            ans.push_back(it.second);
        }
        
        return ans;
    }
};
