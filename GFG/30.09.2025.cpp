class Solution {
  public:
    vector<string> binstr(int n) {
        // code here
        vector<string> ans;
        for(int i=0; i<pow(2,n); i++){
            string b = bitset<20>(i).to_string();
            string t = b.substr(20-n, n);
            ans.push_back(t);
        }
        return ans;
    }
};
