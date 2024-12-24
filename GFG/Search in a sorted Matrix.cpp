bool searchMatrix(vector<vector<int>> &mat, int x) {
        int r=mat.size();
        int c=mat[0].size();
        int j=r*c-1;
        int i=0;
        while(i<=j)
        {
            int mid=i+(j-i)/2;
            int element=mat[mid/c][mid%c];
            if(element==x)return true;
            else if(element<x) i=mid+1;
            else j=mid-1;
        }
        return false;
    }
