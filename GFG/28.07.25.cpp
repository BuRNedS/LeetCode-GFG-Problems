int balanceSums(vector<vector<int>>& mat) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        vector<int> rowsum(n, 0);
        vector<int> colsum(m, 0);
        
        int ans = 0;
        int msum = 0;
        int flag = 0; 
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                rowsum[i] += mat[i][j];
                colsum[j] += mat[i][j];
                
                if(i == n-1)
                {
                    if(msum < colsum[j])
                    {
                        msum = colsum[j];
                        flag = 1;
                    }
                }
            }
            if(msum<rowsum[i])
            {
                msum = rowsum[i];
                flag =0;
            }
        }
        
        if(flag == 0)
        {
            for(int i=0;i<n;i++)
            {
                ans += msum - rowsum[i];
            }
        }
        else
        {
            for(int j=0;j<m;j++)
            {
                ans += msum - colsum[j];
            }
        }
        
        return ans;
    }
