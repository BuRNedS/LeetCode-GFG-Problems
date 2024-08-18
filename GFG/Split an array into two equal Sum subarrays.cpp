bool canSplit(vector<int>& arr) {
        
        float sum=0;
        
        for(int i=0; i<arr.size(); i++){
            sum +=arr[i];
        }
        
        if(sum == 0) return 1;
        
        float temp=0;
        
        for(int i=0; i<arr.size(); i++){
            temp += arr[i];
            
            if(temp == sum/2) return true;
        }
        
        return false;
        
    }
