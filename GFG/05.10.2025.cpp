void solve(int x , int y , int n , vector<vector<int>> & maze ,string & path , set<string>& ans , vector<vector<bool>> & vis){
        if(x == n-1 && y == n-1 ) ans.insert(path);
        int delx[4] = {-1 , 1, 0 ,0 };
        int dely[4] = { 0 , 0 , -1 , 1 };
        for(int i = 0 ; i < 4 ; i++){
            
            int nx = delx[i]+x;
            int ny = dely[i]+y;
            
            if(nx >= 0 && ny >=0 && nx < n && ny < n && maze[nx][ny] && !vis[nx][ny]){
                if(i==0)path.push_back('U');
                if(i==1)path.push_back('D');
                if(i==2)path.push_back('L');
                if(i==3)path.push_back('R');
                vis[nx][ny]=true;
                solve(nx ,ny ,n  , maze ,path, ans , vis);
                vis[nx][ny]=false;
                path.pop_back();
            }
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n =maze.size();
        set<string> res;
        vector<vector<bool>>vis(n , vector<bool>(n,false));
        string path = "";
        vis[0][0]=true;
        solve(0 ,0 ,n  , maze ,path ,  res , vis);
        vector<string> ans (res.begin(),res.end());
        return ans;
    }
