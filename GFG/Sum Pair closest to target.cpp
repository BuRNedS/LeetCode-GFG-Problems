vector<int> sumClosest(vector<int>& arr, int target) {
        // code here
        if(arr.size() == 1)
        {
            return {};
        }
        
        sort(arr.begin(),arr.end());
        int i=0;
        int j=arr.size()-1;
        int ans1 = 0;
        int ans2 = 0;
        int diff;
        int maxi = INT_MAX;
        
        while(i < j)
        {
            int sum = arr[i]+arr[j];
            if(sum == target)
            {
                return {arr[i],arr[j]};
            }
            else
            {
                int rem = abs(target-sum);
                if(maxi > rem)
                {
                    ans1 = arr[i];
                    ans2 = arr[j];
                    maxi = rem;
                    diff = arr[j]-arr[i];
                }
                else if(maxi == rem)
                {
                    int di = arr[j]-arr[i];
                    if(diff < di)
                    {
                        ans1 = arr[i];
                        ans2 = arr[j];
                        diff = di;
                    }
                }
            }
            
            if(sum < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return {ans1, ans2};
    }
