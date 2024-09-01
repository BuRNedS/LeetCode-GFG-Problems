int maxPathSum(vector<int> &arr1, vector<int> &arr2) {
        // Code here
        int i = arr1.size()-1, j = arr2.size()-1;
        
        int max_path = 0, arr1_path = 0, arr2_path = 0;
        
        while(i >= 0 && j >= 0)
            if(arr1[i] > arr2[j])
                arr1_path += arr1[i--];
            else if(arr1[i] < arr2[j])
                arr2_path += arr2[j--];
            else
            {
                max_path += max(arr1_path + arr1[i--], arr2_path + arr2[j--]);
                arr1_path = arr2_path = 0;
            }
        
        while(i >= 0)
            arr1_path += arr1[i--];
        while(j >= 0)
            arr2_path += arr2[j--];
        
        max_path += max(arr1_path, arr2_path);
        
        return max_path;
    }
