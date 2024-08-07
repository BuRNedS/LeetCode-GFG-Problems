class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
       vector<int>result;
       for(auto it:arr1){
           result.push_back(it);
       }
       for(auto it:arr2){
           result.push_back(it);
       }
       sort(begin(result),end(result));
      return result[k-1];
    }
};
