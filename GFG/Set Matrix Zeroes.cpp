void setMatrixZeroes(vector<vector<int>> &mat) {
        int r=mat.size();
        int c=mat[0].size();
        bool fr=false;
        int fc=false;
        for(int i=0;i<r;i++)
        {
            if(mat[i][0]==0)
            {
                fc=true;
                break;
            }
        }
        for(int j=0;j<c;j++)
        {
            if(mat[0][j]==0)
            {
                fr=true;
                break;
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(mat[i][j]==0)
                {
                    mat[i][0]=0;
                    mat[0][j]=0;
                }
            }
        }
        for(int i=1;i<r;i++)
        {
            for(int j=1;j<c;j++)
            {
                if(mat[0][j]==0 || mat[i][0]==0)
                {
                    mat[i][j]=0;

                }
            }
        }
        if(fr)
        {
            for(int i=0;i<c;i++)
            {
                mat[0][i]=0;
            }
        }
        if(fc)
        {
            for(int i=0;i<r;i++)
            {
                mat[i][0]=0;
            }
        }
    }

