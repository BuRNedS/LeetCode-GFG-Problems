string smallestWindow(string &s, string &p) {
        // code here
        int n=s.size(),m=p.size();
        int start=-1,end=-1,mini=INT_MAX;
        
        unordered_map<char,int>mp;
        for(char &ch:p){
            mp[ch]++;
        }
        
        if(m>n) return "";
        int i=0,j=0;
        int count=m;
        while(j<n){
            if(mp[s[j]]>0){
                count--;
            }
            mp[s[j]]--;
            
            if(count>0) {
                j++;
            } else if(count==0){
                if(j-i+1<mini){
                    mini=min(mini,j-i+1);
                    start=i,end=j;
                } 
                
                while(count==0){
                    if(mp.find(s[i])!=mp.end()){
                        mp[s[i]]++;
                        if(mp[s[i]]==1) count++;
                        if(count==1){
                            if(j-i+1<mini){
                                mini=min(mini,j-i+1);
                                start=i,end=j;
                            } 
                        }
                    }
                    
                    i++;
                }
                
                j++;
            }
        }
        
        if(start==-1 && end==-1) return "";
        
        return s.substr(start,end-start+1);
    }
