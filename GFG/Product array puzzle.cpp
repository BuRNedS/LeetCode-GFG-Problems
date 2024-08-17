class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
   vector<long long int> productExceptSelf(vector<long long int>& nums) {
    int n = nums.size();
    vector<long long int> ans(n);

    for (int i = 0; i < n; i++) {
        long long int pro=1;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                pro *= nums[j];
            }
        }
        ans[i]=pro;
    }
    return ans;
}

};
