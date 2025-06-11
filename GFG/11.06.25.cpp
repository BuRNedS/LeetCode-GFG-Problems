class Solution {
  public:
    int findLength(vector<int> &color, vector<int> &radius) {
        // code here
        stack<pair<int, int>> stk; //{color, radius}
        int n = color.size();
        for (int i = 0; i < n; i++) {
            int c = color[i];
            int r = radius[i];
            
            if (!stk.empty() && ((stk.top().first == c && stk.top().second == r)))
                stk.pop();
            else
                stk.push({c, r});
        }
        return stk.size();
    }
};

