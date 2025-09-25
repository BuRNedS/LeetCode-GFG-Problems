class Solution {
  public:
    vector<string> generateBinary(int n) {
        vector<string> result(n);
        result[0] = "1";
        for(int i = 2;i<=n;i++){
            result[i-1] = result[(i/2)-1];
            if(i%2 == 0){
                result[i-1].push_back('0'); 
            }
            else{
                result[i-1].push_back('1'); 
            }
        }
        
        return result;
    }
};
