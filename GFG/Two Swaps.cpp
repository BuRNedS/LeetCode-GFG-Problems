bool checkSorted(vector<int> &arr) {
        int n=arr.size();
        int count=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                count++;
            }
        }
        if(count==1 || count==2 || count>4) return false;
        if(count==0 || count==3) return true;
        for(int i=0;i<n;i++){
            if(arr[i]!=i+1){
                if(arr[arr[i]-1]!=i+1) return false;
            }
        }
        return true;
    }

