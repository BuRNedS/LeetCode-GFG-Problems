
vector<int> longestSubarray(vector<int>& arr, int x) {
        int n=arr.size();
        int i=0,j=0;
        deque<int> mn,mx;
        int st=0,en=0;
        while(j<n){
            while(!mn.empty() && mn.back()>arr[j]) mn.pop_back();
            while(!mx.empty() && mx.back()<arr[j]) mx.pop_back();
            mx.push_back(arr[j]);
            mn.push_back(arr[j]);
            if(!mx.empty() && !mn.empty() && (mx.front()-mn.front() <= x)){
                if((en-st)<(j-i)) { en=j; st=i; };
                j++;
            }else if(i<j && !mx.empty() && !mn.empty() && (mx.front()-mn.front() > x)){
                if(arr[i]==mn.front()) mn.pop_front();
                if(arr[i]==mx.front()) mx.pop_front();
                i++;j++;
            }
        }
        if(st==en) return {arr[0]};
        vector<int> res;
        for(int i=st;i<=en;i++) res.push_back(arr[i]);
        return res;
    }
