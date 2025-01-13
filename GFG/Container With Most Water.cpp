int maxWater(vector<int> &arr) {
        int n = arr.size();
        
        int left = 0, right = n-1;
        
        int maxWaterOccupied = 0;
        
        while(left < right){
            int width = right - left;
            
            int height = min(arr[left], arr[right]);
            
            int currWaterOccupied = width * height;
            
            maxWaterOccupied = max(maxWaterOccupied, currWaterOccupied);
            
            if(arr[left] < arr[right]){
                left += 1;
            }else{
                right -= 1;
            }
        }
        
        return maxWaterOccupied;
    }
