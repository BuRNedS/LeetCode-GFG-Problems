class Solution {
public:
    int countPairs(vector<int> &arr, int target) {
        // Hash map to store the frequency of elements encountered
        unordered_map<int, int> mp;  
        int cnt = 0; // Counter to keep track of pair count

        // Traverse the array
        for (int i = 0; i < arr.size(); ++i) {
            // Required value to form a pair with arr[i]
            int req = target - arr[i];

            // Check if the required value exists in the map
            if (mp.find(req) != mp.end()) {
                cnt += mp[req]; // Add the frequency of the required value
            }

            // Increment the frequency of the current value in the map
            mp[arr[i]]++;
        }

        return cnt; // Return the total number of pairs
    }
};
