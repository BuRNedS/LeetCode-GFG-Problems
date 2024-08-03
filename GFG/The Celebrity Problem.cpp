class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n=mat.size();
        for(int j=0;j<n;j++)
        {
            int count=0;
            for(int i=0;i<n;i++)
            {
                if(i==j)
                {
                    continue;
                }
                if(mat[i][j]==1)
                {
                    count++;
                }
            }
            if(count==n-1)
            {
                bool flag=true;
                for(int k=0;k<n;k++)
                {
                    if(j==k)
                    {
                        continue;
                    }
                    if(mat[j][k]==1)
                    {
                        flag=false;
                       break;
                    }
                }
                if(flag==true)
                {
                    return j;
                    //j is the celebrity
                }
            }
        }
        
        return -1; 
        //no celebrity exits
    }
};
