class Solution {
  public:
    int find(vector<int>&arr){
        int l=INT_MIN;
        for(int i=0;i<arr.size();i++){
            if(arr[i]>l){
                l=arr[i];
            }
        }
        return l;
    }
    int kthMissing(vector<int> &arr, int k) {
        // Your code goes here
        map<int,int>mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int m=find(arr);
        vector<int>a;
        for(int i=1;i<m;i++){
            a.push_back(i);
        }
        for(int i=0;i<a.size();i++){
            if(mp.find(a[i])==mp.end()){
                --k;
                if(k==0){
                    return a[i];
                }
            }
        }
        return m+k;
    }
};
