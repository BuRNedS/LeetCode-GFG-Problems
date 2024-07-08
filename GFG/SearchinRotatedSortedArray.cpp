class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // complete the function here
        int n = arr.size();
        int low=0, high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            
            if(arr[mid] == key) return mid;
            
            
            // Checking whether the left half is sorted or not
            if(arr[mid] >= arr[low]) {
                // Checking whether key lies beteen low and mid or not
                if(key>=arr[low] && key<=arr[mid]) high = mid-1;
                else low = mid+1;
            } 
            else {
                // Checking whether key lies between mid and high or not
                if(key>=arr[mid] && key<=arr[high]) low = mid+1;
                else high = mid-1;
            }
        }
        
        return -1;
    }
};
