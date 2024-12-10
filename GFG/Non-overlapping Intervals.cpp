class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        // code here
        sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1], count=0;
        for(int i=1; i<intervals.size(); i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd = intervals[i][1];
            }else{
                prevEnd = min(prevEnd, intervals[i][1]);
                count += 1;
            }
        }
        return count;
    }
};
