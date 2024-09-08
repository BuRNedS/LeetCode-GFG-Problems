class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int count=1;
        int maxcount = 1;
        if(nums.size() == 0){
            return 0;
        }
        for(int i=0; i<nums.size()-1; i++){
            
            if(nums[i+1] == nums[i] + 1){
                count++;
            }
            else if(nums[i+1] == nums[i]){
                continue;
            }
            else{
                count =1;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};
