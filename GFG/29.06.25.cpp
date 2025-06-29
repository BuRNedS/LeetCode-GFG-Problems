class Solution {
  public:
    bool f(int sum , vector<int>& arr, int k){
       int s = 0 ; 
       for(int i : arr){
           s += i ;
           if(s > sum){
               k -- ; s = i ;
           }
       }
       return (k > 0 && s <= sum) ;
    }
    
    int splitArray(vector<int>& arr, int k) {
        int s = *max_element(arr.begin(), arr.end()) ; 
        int e = accumulate(arr.begin() , arr.end() , 0) ;
        int ans = -1 ;
        while(s <= e){
            int mid = s + (e-s) / 2 ;
            if(f(mid , arr , k)){
                ans = mid ;
                e = mid - 1 ;
            }
            else{
                s = mid + 1 ;
            }
        }
        return ans ;
    }
};
