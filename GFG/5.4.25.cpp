
class Solution {
  public:
    int row,col;
    void islandHelper(vector<vector<char>>&grid,vector<vector<int>>&vis,int i,int j)
    {
        if(i>=row||i<0||j>=col||j<0||grid[i][j]=='W'||vis[i][j]==1)return ;
        vis[i][j] = 1;
        islandHelper(grid,vis,i+1,j);
        islandHelper(grid,vis,i-1,j);
        islandHelper(grid,vis,i,j+1);
        islandHelper(grid,vis,i,j-1);
        islandHelper(grid,vis,i+1,j+1);
        islandHelper(grid,vis,i+1,j-1);
        islandHelper(grid,vis,i-1,j+1);
        islandHelper(grid,vis,i-1,j-1);
    }
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        row = grid.size();
        col = grid[0].size();
        vector<vector<int>>vis(row,vector<int>(col,0));
        int islands = 0;
        for(int i =0 ;i<row;i++)
        {
            for(int j = 0;j<col;j++)
            {
                if(!vis[i][j]&&grid[i][j]=='L')
                {
                    islands++;
                    islandHelper(grid,vis,i,j);
                }
            }
        }
        return islands;
        
    }
};
