class Solution {
  public:
    int BinarySearch(vector<int> &arr, int val){
        int l = 0;
        int r = arr.size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(arr[m] == val){
                return m;   
            }
            if(arr[m]>=val){
                r = m-1;   
            }
            if(arr[m]<val){
                l = m+1;
            }
        }
        return r;
    }
    vector<int> GetPrimes(int N){
        vector<bool> seives(N+1,1);
        vector<int> primes;
        int cnt = 1;
        for(int i = 2;i<=N;i++){
            if(seives[i]){
                primes.push_back(i);
                for(int j = i+i;j<=N;j+=i){
                    seives[j] = 0;
                }
            }
        }
        
        return primes;
    }
    int CheckPow8(int prime, int n){
        long long N = n;
        long long p = 1;
        
        for(int i = 1;i<=8;i++){
            p *= prime;
            if(p > N)return 0;
        }
        
        return 1;
    }
    int countNumbers(int n) {
        /*
        
        n = (a^x)*(b^y)*(c^z)
        where a, b, c are prime factors of n with x, y, z powers
        
        num of factors = (x+1)*(y+1)*(c+1)
        
        since we have to find numbers with num of factor = 9
        
        there are only 2 possibilities
        
        Case 1. 
            
            n = a^8
            so,
            num of factors = (8+1) = 9
        
        Case 2.
            n = a^2 * b^2
            so,
            num of factors = (2+1)*(2+1) = 9
            
        */
        int cnt = 0;
        vector<int> primes = GetPrimes(sqrt(n));
        
        for(int i = 0;i<primes.size();i++){
            int prime_num = primes[i];
            
            /* 
            
            Case 1.
            
            checking for the case (p)^8 <= n
            
            */
            cnt += CheckPow8(prime_num, n);
            
            /*
            
            Case 2.
            
            checking for the case
            
                (p1)^2 * (p2)^2 <= n, where p1 = prime_num
                
            so,
            
                p2 <= sqrt(n) / (p1)
            
            this relation shows that primes would always be less than sqrt(n)
            thats why we only find primes upto sqrt(n)
            
            after finding maximum value of p2
            we would add to our answer
            
            ans += (primes_upto(p2) - primes_upto(p1))
            
            for example p1 = 2, p2 <= 10
            so, primes upto p1 = 1
                primes upto p2 = 4 (i.e, 2,3,5,7)
                
                so ans += 3
                
            */
            int sqrt_n_by_prime = sqrt(n)/prime_num;
            
            if(prime_num >= sqrt_n_by_prime)break; // cases start repeating in reverse order
            
            auto upper_idx = BinarySearch(primes,sqrt_n_by_prime);
            auto lower_idx = BinarySearch(primes,prime_num);
            cnt +=  upper_idx - lower_idx;
            
        }
        
        return cnt;
    }
};
