class Solution {
  public:
    int findresult(vector<int>& arr, int result) {
        // code here
        int l=0;
        int r=arr.size()-1;
        while (l<=r){
            int m =l +(r-l)/2;
            if(arr[m]==result)
              return m;
            if(m>l && arr[m-1] ==result)
              return m - 1;
            if(m <r &&arr[m+1]==result)
               return m+1;
            if(arr[m]>result) 
               r =m-2; 
            else
               l =m+2; 
        }
        return -1;
    }
};
