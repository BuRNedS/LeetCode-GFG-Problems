class Solution {
  public:
    bool sameFreq(string& s) {
        // code here
        vector<int> chars(26,0);
        
        for(auto it:s){
            chars[it-'a']++;
        }
        
        int freq = -1;
                  bool flag = true;
                 for(int j = 0;j<26;j++){
                     if(freq == -1 && chars[j] > 0) freq = chars[j];
                     else if(freq != -1 && chars[j] > 0 && chars[j] != freq){
                         flag = false;
                         break;
                     }
                 }
                 if(flag) return true;
                 
                 
        for(int i=0;i<26;i++){
             if(chars[i] > 0){
                  chars[i]--;
                 int freq = -1;
                  bool flag = true;
                 for(int j = 0;j<26;j++){
                     if(freq == -1 && chars[j] > 0) freq = chars[j];
                     else if(freq != -1 && chars[j] > 0 && chars[j] != freq){
                         flag = false;
                         break;
                     }
                 }
                 if(flag) return true;
                 chars[i]++;
             }
        }
        return false;
    }
};
