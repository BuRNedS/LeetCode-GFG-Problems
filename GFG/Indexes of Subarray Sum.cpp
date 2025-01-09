vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        int i=0,j=0,sum=0;
        while(j<arr.size()){
            sum+=arr[j];
            if( sum>target){
                while(i<=j && sum>target){
                    sum-=arr[i];
                    i++;
                }
            }
            if(sum==target){
                return {i+1,j+1};
            }
            j++;
        }
        return {-1};
    }
