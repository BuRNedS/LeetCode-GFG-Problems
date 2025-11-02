class Solution {
  public:
    int maxEdgesToAdd(int n, vector<vector<int>>& edges) {
        // code here
        return (n*n-n)/2-edges.size();
    }
};
