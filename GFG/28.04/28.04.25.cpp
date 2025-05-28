class Solution {
  public:
    bool ValidCorner(vector<vector<int> >& mat) {
        // code here
         int rows = mat.size();
        if (rows == 0)
        return false;
        int cols = mat[0].size();
        unordered_map<int,unordered_set<int>> s;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j<cols-1; j++) {
                if (mat[i][j]==1) {
                    for (int k=j + 1; k < cols; k++) {
                        if (mat[i][k] == 1) {
                            if (s[j].count(k)) {
                                return true; 
                            }
                            s[j].insert(k);
                        }
                    }
                }
            }
        }

        return false;
    }
};
