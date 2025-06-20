class Solution {
public:
    bool validgroup(vector<int> &arr, int k) {
        if(arr.size() % k != 0) return false;
        sort(arr.begin(), arr.end());

        int cnt = 1;

        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] == 1) {
                cnt++;
            } else if (arr[i] == arr[i - 1]) {
                continue; // allow duplicates
            } else {
                if (cnt % k != 0) return false;
                cnt = 1;
            }
        }

        return cnt % k == 0;
    }
};
