class Solution {
  public:

// swap without using extra space
    void swapNum(int &a, int &b) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int idx = a.size() -1;
        int jdx = 0;
        
        while (idx >= 0 && jdx < b.size() ) {
            if (a.at(idx) > b.at(jdx)) {
                swapNum(a.at(idx), b.at(jdx));
            }
            idx--;
            jdx++;

        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
    }
};
