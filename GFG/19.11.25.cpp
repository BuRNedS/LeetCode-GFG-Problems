"class Solution {
  public:
    int minCostPath(vector<vector<int>>& mat) {
        // code here
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        
        pq.push({0,0,0});
        
        vector<pair<int,int>> dir = {{-1,0},{1,0},{0,1},{0,-1}};
        
        int n = mat.size(),m = mat[0].size();
        
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        
        while(pq.size()!=0){
            vector<int> t = pq.top();pq.pop();
            int x = t[1],y=t[2],c=t[0];
            
            if(dp[x][y]>c){
                dp[x][y] = c;
            }else{
                continue;
            }
            
            if(x==n-1 && y==m-1){
                 break;  
            }
            
            for(int i=0;i<4;i++){
                int X = x+dir[i].first,Y = y+dir[i].second,C=0;
                if(X<0 || Y<0 || X>=n || Y>=m)continue;
                
                C = max(c,abs(mat[x][y]-mat[X][Y]));
                pq.push({C,X,Y});
            }
        }
        
        return dp[n-1][m-1];
    }
};"
 https://www.geeksforgeeks.org/problems/path-with-minimum-effort/1#:~:text=class%20Solution%20%7B%0A%20%20public,1%5D%5Bm%2D1%5D%3B%0A%20%20%20%20%7D%0A%7D%3B
