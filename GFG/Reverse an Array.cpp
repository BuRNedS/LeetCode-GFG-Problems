void reverseArray(vector<int> &arr) {
        // code here
        int length = arr.size();
        int mid = length /2 ;
        for(int i = 0; i < mid ; i++){
            swap(arr[i], arr[length-i-1]);
        }
    }
