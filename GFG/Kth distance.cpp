bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // your code
        map<int, int> mp;
        for(int i=0; i<arr.size(); i++)
        {
            if(mp[arr[i]])
            {
                if(i - mp[arr[i]] <= k)
                {
                    return true;
                }
                else
                {
                    mp[arr[i]] = i;
                }
            }
            else
            {
                mp[arr[i]] = i;
            }
        }
        return false;
    }
