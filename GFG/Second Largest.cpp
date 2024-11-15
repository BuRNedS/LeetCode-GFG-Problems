int getSecondLargest(vector<int> &arr) {
        // Code Here
        int n=arr.size();
        int maxi=-1,sec_max=-1;
       // sort(arr.begin(),arr.end());
         for(int i=0;i<n;i++){
            // find the largest and second largest element

            if(maxi<arr[i]){
                sec_max=maxi;
                maxi=arr[i];
             }
             else if(sec_max<arr[i] && arr[i]!=maxi) sec_max=arr[i]; // second element should               //be not equal to largest one
              
         }
        return sec_max;
    }
