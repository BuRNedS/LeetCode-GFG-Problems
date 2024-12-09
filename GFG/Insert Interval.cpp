vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.insert(intervals.end() , newInterval);
        sort(intervals.begin() , intervals.end());
        
        vector<vector<int>> ans;
        int start = intervals[0][0];
        int end = intervals[0][1];
        int size = intervals.size();
        
        for(int i = 0;i<size;i++){
            if(end >= intervals[i][0]){
                end = max(end , intervals[i][1]);
            }
            else {
                // bigger val
                // change the interval
                ans.push_back({start , end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        
        // push the last interval
        ans.push_back({start , end});
        return ans;
    }
