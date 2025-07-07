class Solution {
  public:
    vector<int> nextLargerElement(vector<int> &arr) {
        int n = arr.size();
        vector<int> res(n, -1);
        stack<int> stk;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= arr[i % n]) {
                stk.pop();
            }
            if (i < n && !stk.empty()) {
                res[i] = stk.top();
            }
            stk.push(arr[i % n]);
        }
        return res;
    }
};
