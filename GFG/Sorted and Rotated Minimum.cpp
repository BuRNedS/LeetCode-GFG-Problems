class Solution {
  public:
    int findMin(vector<int>& arr) {
        // complete the function here
        int mini = INT_MAX;
        
        for(int i=0; i<arr.size(); i++){
            if(arr[i] < mini){
                mini = arr[i];
            }
        }
        return mini;
    }
};
