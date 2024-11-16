void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n=arr.size(),j=0;
        for(int i=0;i<n;i++){
            if(arr[i]){
                swap(arr[i],arr[j]);
                j++;
            }
        }  
    }
