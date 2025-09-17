class Solution {
  public:
    string decodedString(string &s) {
        // code here
     string ans;
        
        for(char c : s){
            if(c!=']') ans +=c;
            else{
                string word;
                while(ans.back()!='['){
                    word= ans.back() + word;
                    ans.pop_back();
                }
                
                ans.pop_back();
                string k; 
                
                while(!ans.empty() && isdigit(ans.back())){
                    k = ans.back() + k;
                    ans.pop_back();
                }
                
                int num=stoi(k);
                
                while(num--){
                    ans.append(word);
                }
            }
        }
        
        return ans;
    }
};
