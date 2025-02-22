

stack<int> st;
        st.push(-1);
        int maxy=0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(i);
            } else {
                st.pop();
                if (st.empty()) {
                    st.push(i);
                } else {
                    maxy = max(maxy, i - st.top());
                }
            }
        }

        return maxy;
