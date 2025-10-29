class Solution {
  public:
    int ans = 0;
    int solve(int node, vector<vector<int>> &adj, vector<int> &vis)
    {
        int max1 = 0, max2 = 0;
        for(auto it : adj[node])
        {
            if(!vis[it])
            {
                vis[it] = 1;
                int len = solve(it,adj,vis);
                if(len+1 > max1)
                {
                    max2 = max1;
                    max1 = len+1;
                }
                else
                    max2 = max(max2,len+1);
                vis[it] = 0;
            }
        }
        ans = max(ans, max1+max2);
        return max1;
    }
    int diameter(int V, vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> adj(V);
        for(int i=0; i<n; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(V,0);
        vis[0] = 1;
        solve(0,adj,vis);
        return ans;
    }
};
