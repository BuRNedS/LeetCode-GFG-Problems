vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        // code here
        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back({intervals[0][0],intervals[0][1]});
        int index=0;
        
        //cout<<intervals[0][0]<<" "<<intervals[0][1]<<endl;
        
        for(int i=1;i<intervals.size();i++){
            
            //cout<<intervals[i][0]<<" "<<intervals[i][1]<<endl;
            
            if(intervals[i][0]<=ans[index][1]){
                ans[index][1]=max(ans[index][1],intervals[i][1]);
            }else{
                ans.push_back(intervals[i]);
                index++;
            }
        }
        return ans;
        
    }
