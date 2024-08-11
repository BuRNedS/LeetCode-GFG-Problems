vector<int> JobScheduling(Job arr[], int n) 
    { 
        // your code here
        vector<pair<int,int>> v;
        int count=0;
        int value=0;
        vector<int> ans;
        priority_queue<int> pq;
        vector<pair<int,int>> flag;
        // int flag=0;
        for(int i = 0;i<n;i++){
            v.push_back({arr[i].dead,arr[i].profit});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        flag.push_back({v[0].first,1});
        int j = 0;
        for(int i =1;i<n;i++){
            if(v[i].first!=flag[j].first){
                flag.push_back({v[i].first,1});
                flag[j].second = flag[j].first-v[i].first;
                j++;
            }
        }
        if(flag[flag.size()-1].first!=1){
            int n2 = flag.size();
            flag.push_back({1,
                flag[n2-1].first-1
            });
        }
        j = 0;
        int i =0;
        while(i<v.size() && j<flag.size()){
            if(v[i].first==flag[j].first){
                pq.push(v[i].second);
                // pushed =true;
                count++;
                value+=pq.top();
                pq.pop();
                flag[j].second--;
                if(flag[j].second==0){
                    j++;
                }
            }else if(v[i].first<flag[j].first){
                while(!pq.empty() && flag[j].second!=0){
                    count++;
                    value+=pq.top();
                    pq.pop();
                    flag[j].second--;
                }
                j++;
                i--;
            }else if(v[i].first>flag[j].first){
                pq.push(v[i].second);
            }
            i++;
        }
        
        while(j<flag.size() && !pq.empty()){
            count++;
            value+=pq.top();
            pq.pop();
            flag[j].second--;
            if(flag[j].second==0){
                j++;
            }
        }
        ans={count,value};
        return ans;
    }
