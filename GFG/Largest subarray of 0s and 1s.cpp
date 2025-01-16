class Solution {
  public:
    int maxLen(vector<int> &arr) {
        // Your 
        unordered_map<int,int>mp;
        int sum=0;
        int maxlen=0;
        
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0)sum+=-1;
            else sum+=1;
            
            if(sum==0){
                maxlen=i+1;
            }
            
            if(mp.find(sum)!=mp.end()){
                maxlen=max(maxlen,i-mp[sum]);
            }
            else{
                mp[sum]=i;
            }
            
              }
        
        
        return maxlen;
        
    }
};

