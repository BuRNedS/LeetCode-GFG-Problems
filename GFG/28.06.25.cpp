class Solution {
  public:
    int solve(int num , vector<int>& nums) {
        int s = 0, e = nums.size() - 1;
        int ans = -1;
    
        while (s <= e) {
            int mid = s + (e - s) / 2;
            if (nums[mid] <= num) {
                ans = mid;
                s = mid + 1;
            } else {
                e = mid - 1;
            }
        }
    
        return ans + 1;
    }

    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        int n = a.size() , m = b.size();
        
        sort(b.begin(),b.end());
        vector<int>ans;
        
        for(int i = 0; i < n;i++){
            ans.push_back(solve(a[i],b));
        }
        
        return ans;
    }
};
