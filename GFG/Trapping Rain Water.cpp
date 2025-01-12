class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        
        int n=arr.size();
        vector<int>next(n);
        int prev_max=0, result=0;
        
        next[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--)
          next[i]=max(next[i+1], arr[i]);
          
          for(int i=0; i<n;i++){
              prev_max=max(prev_max, arr[i]);
              result+=min(prev_max, next[i])-arr[i];
          }
          
          return result;
        
    }
};
