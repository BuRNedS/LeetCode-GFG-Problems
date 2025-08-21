bool isPossible(vector<int>& arr,int k,int diff){
        int n=arr.size(),l=0;
        k--;
        while(k){
            auto it=lower_bound(arr.begin()+l,arr.end(),arr[l]+diff);
            int idx=it-arr.begin();
            
            if(idx<n) k--;
            if(k==0) return true;
            else if(k>0 && idx==n) break;
            
            l=idx;
        }
        
        return false;
    }
  
    int maxMinDiff(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        sort(arr.begin(),arr.end());
        
        int low=0,high=arr[n-1]-arr[0];
        int ans=0;
        while(low<=high){
            int mid=low+(high-low)/2;
            
            if(isPossible(arr,k,mid)){
                ans=mid;
                low=mid+1;
            } else {
                high=mid-1;
            }
        }
        
        return ans;
    }
