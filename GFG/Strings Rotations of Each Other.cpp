bool kmp(string &txt,string &pat){
        string str = pat + "#" + txt;
        int n = str.size();
        vector<int> lps(n,0);
        for(int i=1;i<n;i++){
            int x = lps[i-1];
            while(str[x]!=str[i]){
                if(x==0){
                    x=-1;
                    break;
                }
                x=lps[x-1];
            }
            lps[i]=x+1;
        }
        for(auto x:lps){
            if(x==pat.size()){
                return true;
            }
        }
        return false;
    }
    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        // Your code here
        string str = s1+s1;
        return kmp(str,s2);
    }
