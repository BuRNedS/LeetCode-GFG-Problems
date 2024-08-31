vector<int> find3Numbers(vector<int> &arr) {
        // Code here
        int n = arr.size();
        // preprocessing to get the left minimum and right maximum for every index i
        vector<int> left(n, -1), right(n, -1);
        int li = 0, ri=n-1;
        for(int i=1; i<n; ++i){
            // calculating left minimum
            if(arr[li]<arr[i]){
                left[i] = li;
            }else{
                li = i;
            }
            // calculating right maximum
            if(arr[ri]>arr[n-i-1]){
                right[n-i-1] = ri;
            }else{
                ri = n-i-1;
            }
        }
        for(int i=1; i<n; ++i){
            if(left[i]!=-1 && right[i]!=-1){
                return {arr[left[i]], arr[i], arr[right[i]]};
            }
        }
        return {};
    }
