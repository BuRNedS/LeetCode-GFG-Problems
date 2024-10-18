class Solution {
  public:
    int getSingle(vector<int>& arr) {
        // code here
        int n = arr.size();
        sort(arr.begin(),arr.end());
        int cnt = 0;
        for(int i=0;i<n;i++){
            
            if(i == n-1){
               if(arr[i] == arr[i-1]){
                   cnt++;
                    if(cnt % 2 !=0) return arr[i];
               }else{
                   return arr[i];
               }
            }
            
            if(arr[i]==arr[i+1]){
                cnt++;
            }
            else if(arr[i] != arr[i+1]){
                cnt++;
                if(cnt%2 !=0) return arr[i];
                cnt=0;
            }
            
        }
    }
};
