bool canAttend(vector<vector<int>> &arr) {
        // Your Code Here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        for(int i=1; i<n; i++){
            if(arr[i-1][1] > arr[i][0])return false;
        }
        return true;
    }
