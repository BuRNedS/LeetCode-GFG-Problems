int maxSubarraySum(vector<int> &arr) {
        // code here...
        int maxi=-1e9;
        int n=arr.size();
        int sum=0;
        
        for(int i=0; i<n; i++){
            sum+=arr[i];
            maxi=max(maxi, sum);
            if(sum<0) sum=0;
        }
        
        return maxi;
    }
