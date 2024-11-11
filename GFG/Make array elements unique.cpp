class Solution {
  public:
    int minIncrements(vector<int>& arr) {
        // Code here
        map<int, int> mp;
        int count=0;
        for(int& i:arr){
            mp[i]++;
        }
        for(auto& p:mp){
            if(p.second>1){
                count+=(p.second-1);
                mp[p.first+1]+=(p.second-1);
            }
        }
        return count;
    }
};
