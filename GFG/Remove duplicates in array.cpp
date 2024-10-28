vector<int> removeDuplicate(vector<int>& arr) 
    {
        vector<int> temp(101,0);
        int j = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(temp[arr[i]] == 0)
            {
                arr[j] = arr[i];
                j++;
                temp[arr[i]]++;
            }
        }
        
        while(j < arr.size())
            arr.pop_back();
            
        return arr;
        // code here
    }
