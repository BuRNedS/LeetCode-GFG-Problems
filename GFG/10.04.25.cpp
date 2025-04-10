
class DisjointSet {
private:
    vector<int>parent;
    vector<int>size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n,1);
        for(int i = 0;i<n;i++) parent[i] = i;
    }
    int findUPar(int node){
        if(node==parent[node]) return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if(ulp_u==ulp_v) return;
        if(size[ulp_u]<size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
    
};
class Solution {
  public:
    int minCost(vector<vector<int>>& houses) {
        // code here
        DisjointSet ds(houses.size());
        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>>>pq;
        for(int i = 0 ;i<houses.size()-1;i++){
            for(int j = i+1;j<houses.size();j++){
                int dis = abs(houses[i][0]-houses[j][0]) + abs(houses[i][1]-houses[j][1]);
                pq.push({dis,{i,j}});
            }
        }
        int ans = 0;
        while(!pq.empty()){
            int cost = pq.top().first;
            int u = pq.top().second.first;
            int v = pq.top().second.second;
            pq.pop();
            if(ds.findUPar(u)!=ds.findUPar(v)){
                ans+=cost;
                ds.unionBySize(u,v);
            }
        }
        return ans;
        
    }
};
