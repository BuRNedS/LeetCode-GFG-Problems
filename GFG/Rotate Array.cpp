void rotateArr(vector<int>& arr, int d) {
        int n = arr.size(), ans = d % n;        
        rotate(arr.begin(), arr.begin()+ans, arr.end());
    }
