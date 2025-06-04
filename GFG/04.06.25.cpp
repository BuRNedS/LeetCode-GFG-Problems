class Solution {
  public:
  void returnMap(unordered_map<char, vector<int>>& mp,string s){
      
      for(int i=0; i<s.length(); i++){
          mp[s[i]].push_back(i);
      }
  }
  bool verify(unordered_map<char, vector<int>>& mp, char ch, int& prv){
      
      if(!mp[ch].empty()){
          for(int i=0; i<mp[ch].size(); i++){
              if((mp[ch][i]!=-1 && prv<mp[ch][i]) || prv==-1){
                 
                  prv=mp[ch][i];
                  mp[ch][i]=-1;
                  return true;
              }
              
          }
      }
  
      return false;
      
  }
  
    int lcs(string start, string s1, string s2){
        unordered_map<char, vector<int>> mp1, mp2, mp3;
        returnMap(mp1, start);
        returnMap(mp2, s1);
        returnMap(mp3, s2);
        
        int c=0;
        int prv1=-1;
        int prv2=-1;
        string s="";
        for(int i=0; i<start.length(); i++){
            char str=start[i];
            // c+=verify(mp1,str,prv1) && verify(mp2, str, prv2) ? 1 : 0;
            if(verify(mp2,str,prv1) && verify(mp3, str, prv2)){
                c+=1;
              
            }
          
            
        }
        return c;
    }
    
    int lcsOf3(string& s1, string& s2, string& s3) {
        int n1=s1.length(), n2=s2.length(), n3=s3.length();
        int minLength=min(n1,min(n2,n3));
        
        if(minLength==n1) return lcs(s1, s2 , s3);
        else if(minLength==n2) return lcs(s2,s1,s3);
        else return lcs(s3, s1, s2);
        
    }
}; 
