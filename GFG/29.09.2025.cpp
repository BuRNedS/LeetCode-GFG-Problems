void findSubArr(vector<int> &arr, int a, int b, vector<vector<int>> &subArrays){
        int n = arr.size();
        for(int i=0; i<n; i++){
            vector<int> temp;
            for(int j=i; j<n; j++){
                temp.push_back(arr[j]);
                if(temp.size() >= a && temp.size() <=b){
                    subArrays.push_back(temp);
                }
            }
        }
    }
    int maxSubarrSum(vector<int>& arr, int a, int b) {
        // code here
        vector<vector<int>> subArrays;
        findSubArr(arr, a, b, subArrays);
        
        vector<int> arrSum;
        for(auto i:subArrays){
            int sum = 0;
            for(auto j:i){
                sum = sum + j;
            }
            arrSum.push_back(sum);
        }
        sort(arrSum.begin(), arrSum.end());
        int n = arrSum.size();
        return arrSum[n-1];
    }
