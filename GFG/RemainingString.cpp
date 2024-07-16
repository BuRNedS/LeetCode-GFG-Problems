 string printString(string s, char ch, int count) {
        string ans = "";
        int cnt = 0;
        for(int i=0; i<s.length(); i++){
            if(s[i]==ch){
                cnt++;
                if(count == cnt){
                    return s.substr(i+1);
                }
            }
        }
        return ans;
    }
