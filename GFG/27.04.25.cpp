class Solution {
  public:
    /*You are required to complete below function */
    string multiplyStrings(string& s1, string& s2) {
        // Your code here
        string temp1;
        string temp2;
        bool isIncludeNeg = false;
        
        int n1 = s1.size();
        int i=0;
        bool p = false;
        while(i<n1){
            if(s1[i]=='0' && p==false){
                i++;
                continue;
            }
            p = true;
            if(s1[i] == '-'){
                isIncludeNeg = !isIncludeNeg;
            }
            else{
                temp1.push_back(s1[i]);
            }
            i++;
        }
        
        int n2 = s2.size();
        i=0;
        p = false;
        while(i<n2){
            if(s2[i]=='0' && p==false){
                i++;
                continue;
            }
            p = true;
            if(s2[i] == '-'){
                isIncludeNeg = !isIncludeNeg;
            }
            else{
                temp2.push_back(s2[i]);
            }
            i++;
        }
        
        int nt1 = temp1.size();
        int nt2 = temp2.size();
        
        if(nt1*nt2 == 0)
            return "0";
            
        //////////////////////
        
        reverse(temp1.begin(), temp1.end());
        reverse(temp2.begin(), temp2.end());
        
        vector<int> res(nt1+nt2, 0);
        
        for(int i=0;i<nt1;i++){
            for(int j=0;j<nt2;j++){
                int c1 = temp1[i]-48;
                int c2 = temp2[j]-48;
                int cm = c1*c2;
                
                res[i+j] += cm;
                res[i+j+1] += (res[i+j]/10);
                res[i+j]%=10;
            }
            
        }
        reverse(res.begin(), res.end());
        int si = 0;
        while(res[si]==0)
            si++;
        
        string resStr;
        for(int i=si;i<(nt1+nt2);i++){
            resStr.push_back(res[i]+'0');
        }
            
        string pre = "";
        if(isIncludeNeg)
            pre = "-";
        
        return pre + resStr;
            
        
    }
};
