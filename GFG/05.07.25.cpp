class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int x = max(arr[0],arr[1]); // min1
        int y = min(arr[0],arr[1]); // min2
        int sum = x+y;
        for(int i=2;  i<n; i++) {
            if(arr[i]<x && arr[i]>y){
                x = arr[i];
            }
            if(arr[i]<x && arr[i]<y){
                x = y;
                y = arr[i];
            }
            sum = max({sum,x+y,arr[i]+arr[i-1]});
        }
        return sum;
    }
};
