class Solution {
  public:
    int fun(int l, int r, vector<int> &arr, int k){
        if(l==r)
            return l;
        int m = l + (r-l)/2;
        int sum = 0;
        for(auto z : arr){
            sum += (z/m);
            if(z%m)    
                sum++;
        }
        
        if(sum <= k)
            return fun(l, m, arr, k);
        return  fun(m+1, r, arr, k);
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int maxi = arr[0];
        for(auto z : arr){
            maxi = max(maxi, z);
        }
        
        return fun(1, maxi, arr, k);
    }
};
