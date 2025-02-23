
vector<int> nextLargerElement(vector<int>& arr) {
        stack<int> st;
        
        vector<int> ans;
        st.push(-1);
        
        int n = arr.size();
        int i = n-1;
        while(i>=0){
            
            int curr = arr[i];
            if(st.top()==-1){
                ans.push_back(-1);
                st.push(curr);
                i--;
            }
            else if(curr<st.top()){
                ans.push_back(st.top());
                st.push(curr);
                i--;
            }
            else if(curr>=st.top()){
                st.pop();
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
