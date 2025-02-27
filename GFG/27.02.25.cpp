
class Solution {
  public:
    
    stack<pair<int,int>> st;
    
    Solution() {
        // code here
    }
    // Add an element to the top of Stack
    void push(int x) {
        int ele = x;
        if(!st.empty()){
            auto it = st.top();
            ele = min(it.second,x);
        }
        st.push({x,ele});
    }

    // Remove the top element from the Stack
    void pop() {
        if(!st.empty()){
            st.pop();
        }
    }

    // Returns top element of the Stack
    int peek() {
        return (!st.empty()) ? st.top().first : -1;
    }

    // Finds minimum element of Stack
    int getMin() {
       return (!st.empty()) ? st.top().second : -1;
    }
};
