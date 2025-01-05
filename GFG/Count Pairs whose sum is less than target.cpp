int countPairs(vector<int> &arr, int target) {
        // Your code here
        sort(arr.begin(), arr.end());
        int s = 0, e = arr.size()-1;
        int ans = 0;
        
        while (s <= e) {
            int sum = arr[s] + arr[e];
            
            // if sum is greater than or equal to target then shift the right pointer
            if (sum >= target) {
                e--;
            } else {
                // if the sum is less than target then add the number of pairs b/w s and e
                ans += (e - s);
                s++;
            }
        }
        
        return ans;
    }
