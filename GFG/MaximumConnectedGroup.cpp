int dfs(int i, int j, int n, int islandNo, vector<vector<int>>& grid){
       if(i<0 || j<0 || i>=n || j>=n || grid[i][j]==0 || grid[i][j]==islandNo){
           return 0;
       } 
       grid[i][j]=islandNo;
       int a=dfs(i-1, j, n, islandNo, grid);
       int b=dfs(i, j-1, n, islandNo, grid);
       int c=dfs(i+1, j, n, islandNo, grid);
       int d=dfs(i, j+1, n, islandNo, grid);
       return 1+a+b+c+d;
    }
  
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        int islandNo=2;
        int n=grid.size();
        unordered_map<int, int>mpp;
        int ans=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j]==1){
                    int sz=dfs(i, j, n, islandNo, grid);
                    mpp[islandNo]=sz;
                    ans=max(ans, sz);
                    islandNo++;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                unordered_set<int>st;
                int maxS=0;
                if(grid[i][j]==0){
                    if(i>0) st.insert(grid[i-1][j]);
                    if(j>0) st.insert(grid[i][j-1]);
                    if(j<n-1) st.insert(grid[i][j+1]);
                    if(i<n-1) st.insert(grid[i+1][j]);
                    
                    for(auto &it:st){
                        if(mpp.find(it)!=mpp.end()){
                            maxS+=mpp[it];
                        }
                    }
                    maxS+=1;
                    ans=max(maxS, ans);
                }
            }
        }
        return ans;
    }
