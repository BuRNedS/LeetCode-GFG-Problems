bool searchRowMatrix(vector<vector<int>> &mat, int x) {
        for(const auto &row : mat)
            if(binary_search(row.begin(),row.end(),x)) return true;
        return false;
    }
