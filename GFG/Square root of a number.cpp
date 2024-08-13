class Solution {
  public:
    long long int floorSqrt(long long int n) {
        
        // 1). First Approach O(logn)
      
        if(n==1) return 1;
        for(long long i = 1;i<=n/2;i++)
        {
            if(i*i<=n && (i+1) *(i+1)>n) return i;
        }

        // 2).Using floor() funtion 
        //   return floor(pow(n,0.5));
    }
};
