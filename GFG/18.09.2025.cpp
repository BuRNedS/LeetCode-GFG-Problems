#define ll long long int
    vector<long long> nextLargerElement(vector<long long> &arr, int n){
        // Your code here
        vector<ll> ans(n,0);
        stack<ll> stk;
        for(int i=n-1;i>=0;i--) {
            while(stk.size()>0 && stk.top()<=arr[i]) {
                stk.pop();
            }
            if(stk.size()==0) {
                ans[i]=-1;
            } else {
                ans[i]=stk.top();
            }
            stk.push(arr[i]);
        }
        return ans;
    }
