int longestUniqueSubstr(string &arr) {
        
       unordered_map<int , int> mp;
       
       int i =0 , j = -1, tem =0, ans =0 , n = arr.size();
       
       for(i=0; i<n ; ++i){
          
           if(!mp[arr[i]] || mp[arr[i]]-1 < j ){
               mp[arr[i]] = i+1;
               ++tem;
               ans = max(ans , tem);
           }else{
               j = mp[arr[i]];
               tem = i-j+1;
               mp[arr[i]] = i+1;
           } 
       }
       
       
       return ans;
    }
