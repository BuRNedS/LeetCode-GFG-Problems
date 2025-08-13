class Solution {
  public:
    int minSoldiers(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        double no = n/2.0;
        sort(arr.begin(),arr.end());
        int lucky = 0;
        vector<int>res;
        for(int i = 0;i<n;i++){
            if(arr[i]%k == 0){
                lucky++;
            }else{
                res.push_back(k-(arr[i]%k));
            }
        }
        int ans = 0;
        sort(res.begin(),res.end());
        if(lucky >= round(no)) return 0;
        if(lucky < round(no)){
            for(int i=0;i<round(no) - lucky ;i++){
                ans+=res[i];
            }
        }
        return ans;
    }
};
