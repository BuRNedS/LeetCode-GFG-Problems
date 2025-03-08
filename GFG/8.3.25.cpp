
bool check(int i, int j, string& s) {
        
        while(i <= j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    string longestPalindrome(string &s) {
        
        
        int n = s.length();
        string ans =  "";
        string t = "";
        
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(i,j,s)){
                    t = s.substr(i,j-i+1);
                    if(t.length() > ans.length()){
                        ans = t;
                        t = "";
                    }
                }
            }
        }
        return ans;
