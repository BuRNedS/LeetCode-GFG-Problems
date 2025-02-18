vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq; //max-heap
        
        int n=points.size();
        
        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            int d = x*x + y*y;
            
            pq.push({d,i});
            
            if(pq.size()>k)
            pq.pop();
        }
        
        vector<vector<int>> res;
        
        while(!pq.empty()){
            int i = pq.top().second;
            pq.pop();
            res.push_back({points[i][0],points[i][1]});
        }
        
        return res;
    }
