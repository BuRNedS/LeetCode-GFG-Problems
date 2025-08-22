class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        vector<int>ans;
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                ans.push_back(mat[i][j]);
            }
        }
        sort(ans.begin(),ans.end());
        int start=0;
        int end=ans.size()-1;
        int mid=start+(end-start)/2;
        return ans[mid];
    }
};

