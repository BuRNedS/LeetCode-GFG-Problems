class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
            int low = 0;
            int high = arr.size()-1;
            while(low<=high)
            {
                int mid = low+(high-low)/2;
                if(arr[mid]>arr[mid-1]&&arr[mid]>arr[mid+1])return arr[mid];
                else if(arr[mid]>arr[mid-1]&&arr[mid]<arr[mid+1])low = mid+1;
                else if(arr[mid+1]<arr[mid]&&arr[mid-1]>arr[mid])high = mid-1;
            }
            return arr[low];
    }
};
