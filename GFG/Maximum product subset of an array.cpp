long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int ans=1;
        int mod=pow(10, 9)+7;
        int count=0, n=arr.size(), maxi=INT_MIN, t=0;
        if(n==1)
        {
            return arr[0];
        }
        int zero=0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]==0)
            {
                zero++;
            }
            if(arr[i]<0)
            {
                count++;
                maxi=max(maxi, arr[i]);
            }
        }
        if(zero==n)
        {
            return 0;
        }
        if(count==1 && count+zero==n)
        {
            return 0;
        }
        if(count%2==0)
        {
            for(int i=0; i<n; i++)
            {
                if(arr[i]!=0)
                {
                    ans=(ans*arr[i])%mod;
                }
            }
        }
        else{
            for(int i=0; i<n; i++)
            {
                if(arr[i]!=0)
                {
                    ans=(ans*arr[i])%mod;
                }
                
            }
            ans=ans/maxi;
            
        }
       
        return ans;
    }
