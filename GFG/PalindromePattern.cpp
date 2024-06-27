class Solution {
  public:

    string pattern(vector<vector<int>> &arr) {
        // Code Here
        int n=arr.size();
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                int f=1;
                s=s+to_string(arr[i][j]);
            }
            std::string str = std::to_string(i);
            string s2=s;
            reverse(s2.begin(),s2.end());
            if(s==s2) return str+" R";
            
            
            
        }
        for(int i=0;i<n;i++){
            string s="";
            for(int j=0;j<n;j++){
                
                s=s+to_string(arr[j][i]);
            }
            std::string str = std::to_string(i);
            string s2=s;
            reverse(s2.begin(),s2.end());
            if(s==s2) return str+" C";
            
        }
        return "-1";
    }
};