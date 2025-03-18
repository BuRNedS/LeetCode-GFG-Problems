
bool helper(int idx, vector<int>& arr, float sum, vector<vector<int>> &dp)
    {
        if(sum == 0)
            return true;
        if(idx >= arr.size())
            return false;
        if(dp[idx][sum] != -1)
            return dp[idx][sum]; 
        bool ans = helper(idx + 1, arr, sum, dp);
        if(sum - arr[idx] >= 0)
            ans = ans | helper(idx + 1, arr, sum-arr[idx], dp);
        return dp[idx][sum]=ans;
    }
    bool equalPartition(vector<int>& arr) 
    {
        int sum = 0;
        
        for(int i = 0; i < arr.size(); i++)
            sum += arr[i];
        float half = (float)(sum);
        half = half/2;
        //cout << half;
        vector<vector<int>> dp(arr.size() + 1, vector<int>(sum+1,-1));
        return helper(0,arr,half,dp);
        // code here
        
    }
