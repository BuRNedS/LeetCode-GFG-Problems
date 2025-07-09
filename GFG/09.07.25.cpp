class Solution {
public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> left(n, -1), right(n, n); // Initialize left and right arrays
        
        stack<int> st; // Monotonic stack to find boundaries
        
        // Finding right boundaries (next smaller element to the right)
        for(int i = n-1; i >= 0; --i) {
            if(st.empty()) {
                right[i] = n; // No smaller element to the right
                st.push(i);
            } else {
                // Pop elements from stack until a smaller element is found
                while(!st.empty() && arr[i] < arr[st.top()]) {
                    st.pop();
                }
                right[i] = st.empty() ? n : st.top(); // Set right boundary
                st.push(i);
            }
        }
        
        while(!st.empty()) st.pop(); // Clear stack for next pass
        
        // Finding left boundaries (next smaller or equal element to the left)
        for(int i = 0; i < n; ++i) {
            if(st.empty()) {
                left[i] = -1; // No smaller element to the left
                st.push(i);
            } else {
                // Pop elements until a smaller or equal element is found
                while(!st.empty() && arr[i] <= arr[st.top()]) {
                    st.pop();
                }
                left[i] = st.empty() ? -1 : st.top(); // Set left boundary
                st.push(i);
            }
        }
        
        int ans = 0;
        // Calculate total sum of minimums in all subarrays
        for(int i = 0; i < n; ++i) {
            ans += arr[i] * (i - left[i]) * (right[i] - i);
        }
        
        return ans;
    }
};
