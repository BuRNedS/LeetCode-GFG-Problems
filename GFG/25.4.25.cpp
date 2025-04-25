int majorityElement(vector<int>& arr) {
        // code here
        unordered_map<int,int> mpp;
        
        for(auto val:arr){
            mpp[val]++;
        }
        
        for(auto it:mpp){
            if(it.second>arr.size()/2) return it.first;
        }
        return -1;
    }
