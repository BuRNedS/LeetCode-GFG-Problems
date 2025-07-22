class Solution {
    public:
        int missingNumber(vector<int> &arr) {
            set<int> st;
            for(int n1 : arr) {
                if(n1>0){
                    st.insert(n1);
                }
            }
            int posn=1;
            while (true) {
                if(st.find(posn)==st.end()) {
                    return posn;
            }
            posn++;
        }
    }
};
