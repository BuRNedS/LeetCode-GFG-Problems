unordered_map<int,int> prefixSum;
        int n=arr.size(),sum=0,ans=0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            if(sum==k){
                ans=i+1;
            }
            else if(prefixSum.find(sum-k)!=prefixSum.end()){
                ans=max(ans,i-prefixSum[sum-k]);
            }
            if(prefixSum.find(sum)==prefixSum.end()){
                prefixSum[sum]=i;
                
            }
        }
        return ans;
