#define ll long long
class Solution {
  public:
    int powerfulInteger(vector<vector<int>>& in, int k) {
        // code here
        map<ll,ll>mp;
        for(auto it : in){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        ll h=0;
        ll ans=-1;
        ll prev=LLONG_MIN;
        bool is=false;
        for(auto it : mp){
            h+=it.second;
            if(is){
                ans=max(prev,it.first-1);
            }
            if(h>=k){
                is=true;
            }
            else{
                is=false;
            }
            prev=it.first;
        }
        return ans;
    }
};
