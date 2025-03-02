
class Solution {
public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        deque<int> dq;  // Deque to store indices of the array elements
        int n = arr.size();
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // Remove elements from the back of the deque if they are smaller than the current element
            while (!dq.empty() && arr[dq.back()] < arr[i]) {
                dq.pop_back();
            }
            
            // Add the current element index to the deque
            dq.push_back(i);
            
            // Remove elements from the front of the deque if they are out of the current window
            if (dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // If the window has reached size k, add the current maximum (which is at the front of the deque)
            if (i >= k - 1) {
                ans.push_back(arr[dq.front()]);
            }
        }
        
        return ans;
    }
};
