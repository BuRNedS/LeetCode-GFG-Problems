class Solution {
  public:
    vector<int> shortestPath(int V, int m, vector<vector<int>>& edges) {
        unordered_map<int,list<pair<int,int>>>adj;
        for(auto&it:edges){
            int u=it[0];
            int v=it[1];
            int weight=it[2];
            adj[u].push_back({v,weight});
            adj[v].push_back({u,weight});
        }
        
        vector<int>visited(V+1,0);
        vector<int>dist(V+1,INT_MAX);
        dist[1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq; 
        pq.push({0,1});
        vector<int>parent(V+1,-1);
        
        while(!pq.empty()){
            int node=pq.top().second;
            pq.pop();
            
            if(!visited[node]){
                visited[node]=true;
                for(auto v:adj[node]){
                    int nbr=v.first;
                    int weight=v.second;
                    if(dist[nbr]>dist[node]+weight){
                        dist[nbr]=dist[node]+weight;
                        pq.push({dist[nbr],nbr});
                        parent[nbr]=node;
                    }
                }
            }
        }
        
        if(parent[V]==-1)return {-1};
        vector<int>path;
        int t=V;
        while(t!=-1){
         path.push_back(t);
         t=parent[t];
        }
        path.push_back(dist[V]);
        reverse(path.begin(),path.end());
        return path;
    }
};
