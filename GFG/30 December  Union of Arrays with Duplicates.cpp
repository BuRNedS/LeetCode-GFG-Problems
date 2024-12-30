int findUnion(vector<int>& a, vector<int>& b) {
         set<int>ans(a.begin(),a.end());
         ans.insert(b.begin(),b.end());
         return ans.size();
    }
