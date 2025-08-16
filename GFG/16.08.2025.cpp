class cmp {
  public:
    bool operator()(string s1, string s2) {
        return s1 + s2 > s2 + s1;
    }
};
class Solution {
  public:
    string findLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        vector<string> v(n);
        
        string num = "";
        int dig;
        char digit;
        int x;
        
        for(int i = 0; i < n; i++) {
            x = arr[i];
            num = "";
            
            while(x) {
                dig = x % 10;
                digit = dig + '0';
                num = digit + num;
                x /= 10;
            }
            
            if(num == "") v[i] = "0";
            else v[i] = num;
        }
        
        sort(v.begin(), v.end(), cmp());
        
        string ans = "";
        
        int f = 1; // all are zero
        for(string &s: v) {
            if(s != "0") f = 0;
            ans += s;
        }
        if(f) return "0";
        
        return ans;
        
    }
};
