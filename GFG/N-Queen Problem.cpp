class Solution{
public:
    vector<vector<int>> res;
    void solveNQueen(vector<int>& q, int row, int n) {
        if (row == n) 
        {
            res.push_back(q);
            return;
        }

        for (int col = 0; col < n; col++) 
        {
            if (isSafe(q, row, col)) 
            {
                q[row] = col + 1;
                solveNQueen(q, row + 1, n);
            }
        }
    }

    bool isSafe(vector<int>& q, int row, int col) 
    {
        for (int i = 0; i < row; i++) 
        {
            if (q[i] == col + 1 || abs(q[i] - (col + 1)) == abs(i - row))
                return false;
        }
        return true;
    }

    vector<vector<int>> nQueen(int n) {
        // code here
        vector<int> q(n, 0);
        solveNQueen(q, 0, n);
        
        return res;
    }
};
