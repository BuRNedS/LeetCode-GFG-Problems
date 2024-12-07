class Solution {
  public:
  int ans = 0;
  // cconquer
    void merge(vector<int> &arr, int l, int mid, int r){
        vector<int> v1(arr.begin()+l, arr.begin()+mid+1);
        vector<int> v2(arr.begin()+mid+1, arr.begin()+r+1);
        
        int i = 0, j = 0, k = l;
        
        while(i < v1.size() && j < v2.size()){
            if(v1[i] <= v2[j]) arr[k++] = v1[i++];
            else{
                ans = ans + (v1.size() - i);
                arr[k++] = v2[j++];
            }
        }
        
        while(i < v1.size()){
            arr[k++] = v1[i++];
        }
        while(j < v2.size()){
            arr[k++] = v2[j++];
        }
    }
  
    // divide
    void divide(vector<int> &arr, int l, int r){
        if(l < r){
            int mid = (l + r) / 2;
            divide(arr, l, mid);
            divide(arr, mid+1, r);
            merge(arr, l, mid, r);
        }
    }
    // Function to count inversions in the array.
    int inversionCount(vector<int> &arr) {
        // Your Code Here
        divide(arr, 0, arr.size()-1);
        
        return ans;
    }
};
