int findEquilibrium(vector<int> &arr) {
   
        int ans=-1;
        int left=0;
        int right;
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=arr[i];
        }
        
        for(int i=0;i<arr.size();i++){
            right=total-left-arr[i];
            if(left==right){
                ans=i;
                return ans;
            }
            left+=arr[i];
            
        }
        
        return ans;
    }
