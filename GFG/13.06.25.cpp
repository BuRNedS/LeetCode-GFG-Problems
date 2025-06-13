bool check(long m , vector<int>&v,int k){
        int c = 0 ;
        for(int i:v){
            if(i%m==0)c+=i/m ;
            else c+= 1+i/m ;
        }
        return c<=k ;
    }
    int kokoEat(vector<int>& arr, int k) {
        // Code here
        int n = arr.size() ;
        long l = 1 , h = LONG_MAX , mid , ans = h ;
        while(l<=h){
            mid = l + (h-l)/2 ;
            if(check(mid,arr,k)){
                ans = min(ans,mid);
                h = mid - 1;
            }
            else l = mid + 1;
        }
        return ans ;
    }
