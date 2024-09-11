long long minCost(vector<long long>& arr) {
        // Your code hereint
        
       priority_queue<long long,vector<long long>,greater<long long>>pq;
        vector<long long>ansarr;
        long long ans = 0;
        
        //Filling the Priority Queue
        for(int i = 0;i<arr.size();i++){
            pq.push(arr[i]);
        }
        //Taking the sum of the top two elements of PQ and pushing them back 
        //Also taking the sum in ans array.
        while(pq.size()!=1){
            long long sum =pq.top();
            pq.pop();
            sum+=pq.top();
            pq.pop();
            pq.push(sum);
            ansarr.push_back(sum);
        }
       
       //Adding elements of ans array
        for(int i = 0;i<ansarr.size();i++){
            ans+=ansarr[i];
        }
        return ans;
    }
