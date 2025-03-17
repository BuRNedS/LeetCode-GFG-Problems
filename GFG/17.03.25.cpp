
bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n=(int)arr.size();
        bitset<10001>b;
        b[0]=1;
        for(auto it:arr)
        {
            b|=(b<<it);
        }
        return b[sum];
    }
