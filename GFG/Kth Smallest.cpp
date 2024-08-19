int kthSmallest(vector<int> &arr, int k) {
        set<int> s;
        for(auto i:arr) s.insert(i);
        for(auto i=s.begin();i!=s.end();i++){
            k--;
            if(k==0) return *i;
        }
        return -1;
    }
