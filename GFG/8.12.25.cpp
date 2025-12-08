class Solution {

public:

    string build(int i, int j, vector<vector<int>>& split) {

        if (i == j) {

            return string(1, 'A' + i - 1);

        }

        int k = split[i][j];

        string left = build(i, k, split);

        string right = build(k + 1, j, split);

        return "(" + left + right + ")";

    }

 

    string matrixChainOrder(vector<int> &arr) {

        int n = arr.size();

        int m = n - 1; // number of matrices

 

        vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));

        vector<vector<int>> split(m + 1, vector<int>(m + 1, -1));

 

        for (int len = 2; len <= m; len++) {

            for (int i = 1; i + len - 1 <= m; i++) {

                int j = i + len - 1;

                dp[i][j] = INT_MAX;

 

                for (int k = i; k < j; k++) {

                    long long cost = dp[i][k] + dp[k + 1][j] +

                                     1LL * arr[i - 1] * arr[k] * arr[j];

 

                    if (cost < dp[i][j]) {

                        dp[i][j] = cost;

                        split[i][j] = k;

                    }

                }

            }

        }

 

        return build(1, m, split);

    }

};
