class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        map<int,int> m;
        for(auto x : arr){
            m[x]++;
        }
        vector<pair<int,int>> v;
        for(auto it : m){
            v.push_back({it.second,it.first});
        }
        sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
            if(a.first == b.first){return a.second < b.second;}
            return a.first > b.first;
        });
        vector<int> ans;
        for(auto x : v){
            int f=x.first,el=x.second;
            for(int i=0;i<f;i++){
                ans.push_back(el);
            }
        }
        return ans;
    }
};

