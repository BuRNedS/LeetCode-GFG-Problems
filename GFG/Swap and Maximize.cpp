class Solution {
  public:
  
    long long maxSum(vector<int>& arr) {
        // code here
        long long sum=0;
         sort(arr.begin(),arr.end());
         int i=0;
         int j=arr.size()-1;
         while(i<=j){
             sum+=abs(arr[i]-arr[j]);
             sum+=abs(arr[i]-arr[j]);
            i++;
            j--;
         }
         return sum;
    }
};
