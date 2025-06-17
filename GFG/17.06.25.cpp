  int minimumCoins(vector<int>& arr, int k) {
        int n = arr.size();
       //sort the array
       sort(arr.begin(), arr.end());
       //calculate prefixSum
       vector<int> preS(n,0);
       
       int sum = 0;
       for(int i = 0; i<n; i++)
       {
           sum += arr[i];
           preS[i] = sum;
       }
       
       //goal is to keep elements in the range x to x+k
       //for each element x of arr remove all the left and all the right that exceeds x+k
       //at the same time calculte the total coins to remove partially(from right) or fully(from left)
       //and minimize the sum
       int min_c = 1e9;
       for(int i = 0; i<n; i++)
       {
           int x = arr[i];
           //removing all the elements left to x
           int left_c = 0;
           if(i-1>=0)
               left_c = preS[i-1];
            //partially reduce the elements to to keep in the range x+k
            //so find the first element which is > x+k
            int j = upper_bound(arr.begin(),arr.end(), x+k) - arr.begin();
            
            int right_c = (preS[n-1]-preS[j-1]) - (n-j)*(x+k);
                          //total coins in right - totalnoOfEleInRight*maximumLimit
                          
            min_c = min(min_c, left_c+right_c);
       }
        return min_c;
    }
