class Solution {
  public:
    vector<int> MaxRange(vector<int> &arr){
        int n = arr.size();
        vector<int> range(n);
        stack<int> st;
        
        for(int i = 0;i<=n;i++){
            while(!st.empty() and (i == n or arr[i]<arr[st.top()])){
                int idx = st.top();
                st.pop();
                
                int l = st.empty()?-1:st.top();
                int r = i;
                range[idx] = r-l-1;
            }
            st.push(i);
        }
        
        return range;
    }
    vector<int> MaxArray(vector<int> &arr, vector<int> &range){
        int n = arr.size();
        vector<int> maxarr(n,0);
        for(int i = 0;i<n;i++){
            maxarr[range[i]-1] = max(maxarr[range[i]-1], arr[i]);
        }
        return maxarr;
    }
    vector<int> maxOfMins(vector<int>& arr) {
        int n = arr.size();
        vector<int> range =  MaxRange(arr);
        vector<int> maxarr = MaxArray(arr, range);
        
        for(int i = n-2;i>=0;i--){
            maxarr[i] = max(maxarr[i], maxarr[i+1]);
        }
        
        return maxarr;
    }
};
