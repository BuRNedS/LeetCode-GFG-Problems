class Solution {
  public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> res(n);

        int product = 1;
        int zeroCount = 0;

        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) {
                zeroCount++;
            } else {
                product *= arr[i];
            }
        }

        if (zeroCount > 1) {
            return vector<int>(n, 0); // All zeros
        }


        if (zeroCount == 1) {
            for (int i = 0; i < n; i++) {
                if (arr[i] == 0) {
                    res[i] = product;
                } else {
                    res[i] = 0;
                }
            }
            return res;
        }

        for (int i = 0; i < n; i++) {
            res[i] = product / arr[i];
        }

        return res;
    }
};
