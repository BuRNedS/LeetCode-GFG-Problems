class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        // your code here
        for(int i=0;i<mat.size(); i++){
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j] == x){
                    return true;
                }
            }
        }
        return false;
    }
};
