int countPairs(vector<int> &arr, int target) {
        // Complete the function
        int n=arr.size();
        
        int cnt=0;
        unordered_map<int, int>mpp;
        
        for(int i=0; i<n; i++){
            if(mpp.find(target-arr[i])!=mpp.end()){
                cnt+=mpp[target-arr[i]];
            }
            mpp[arr[i]]++;
        }
        
        return cnt;
    }
