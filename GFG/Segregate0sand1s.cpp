void segregate0and1(vector<int> &arr) {
        // code here
        int l=0, r=arr.size()-1;
        while(l<r) {
            if(arr[l] == 1) 
            {
                swap(arr[l], arr[r]);
                r--;
            }
            else l++;
        }
    }
