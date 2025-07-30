class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        // code here
       unordered_map<int, int> prefixSumCount;
    int prefixSum = 0, count = 0;

    // Base case: sum = 0 has occurred once
    prefixSumCount[0] = 1;

    for (int num : arr) {
        prefixSum += num;

        // Check if (prefixSum - k) exists in map
        if (prefixSumCount.find(prefixSum - k) != prefixSumCount.end()) {
            count += prefixSumCount[prefixSum - k];
        }

        // Add/update prefixSum in map
        prefixSumCount[prefixSum]++;
    }

    return count;
    }
};
