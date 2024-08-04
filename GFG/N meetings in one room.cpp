int maxMeetings(int n, int start[], int end[]) {
        // Your code here
        vector<pair<int,int>>v;
        for(int i=0;i<n;i++){
            v.push_back({end[i],start[i]});
        }
        sort(v.begin(),v.end());
        int c=1,d=v[0].first;
        for(int i=1;i<n;i++){
            if(v[i].second > d){
                d=v[i].first;
                c++;
            }
        }
        return c;
    }
