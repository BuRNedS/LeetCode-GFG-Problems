class Solution {
  public:
  
    // toposort method
    void dfs(int node, unordered_map<int, list<int>>& adj, vector<bool>& vis, stack<int>& st) {
        vis[node] = true;
        
        for(auto nbr: adj[node]) {
            if(!vis[nbr]) {
                dfs(nbr, adj, vis, st);
            }
        }
        
        st.push(node);
    }
  
    string findOrder(string dict[], int n, int k) {
        // code here
        unordered_map<int, list<int>> adj;
        for(int i=1; i<n; i++) {
            int j=0;
            int len = min(dict[i].length(), dict[i-1].length());
            while(j < len && dict[i][j] == dict[i-1][j]) {
                j++;
            }
            if(j >= len) continue;
            adj[dict[i-1][j] - 'a'].push_back(dict[i][j] - 'a');
        }
        vector<bool> vis(k, false);
        stack<int> st;
        for(int i=0; i<k; i++) {
            if(!vis[i]) {
                dfs(i, adj, vis, st);
            }
        }
        string ans = "";
        while(!st.empty()) {
            ans += char(st.top() + 'a');
            st.pop();
        }
        // cout << ans << endl;
        return ans;
    }
};
