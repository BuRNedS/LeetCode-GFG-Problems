

vector<int> kLargest(vector<int>& arr, int k) {
       sort(arr.begin(),arr.end());
       int n=arr.size();
       vector<int>ans;
       for(int i=n-1;i>=(n-k);i--)
       {
           ans.push_back(arr[i]);
       }
       return ans;
    }

