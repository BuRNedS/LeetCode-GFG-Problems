int countgroup(vector<int>& arr) {
        // Complete the function
        int x = 0;
        for(auto it:arr)
            x ^= it;
        
        return x==0 ? (1 << (arr.size()-1))-1 : 0;
    }
