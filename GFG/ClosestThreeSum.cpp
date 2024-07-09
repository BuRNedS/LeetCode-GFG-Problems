class Solution {
  public:
     int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        vector<int>ans;
        int mini = INT_MAX;
        sort(arr.begin(),arr.end());
        for(int i=0; i<arr.size(); i++)
        {
            int start = i+1;
            int end = arr.size()-1;
            
                while(start < end)
                {
                    int sum = arr[i] + arr[start] + arr[end];
                    if(sum == target)
                    {
                      return target;
                    }
                    
                    int diff = abs(target - sum);
                    ans.push_back(sum);
                    if(mini > diff)
                    {
                        mini = diff;
                    }
                    
                    if(sum < target)
                    {
                        start++;
                    }
                    else{
                        end--;
                    }
                }
        }
        int tempE = mini + target;
        for(int i=0; i<ans.size(); i++)
        {
            if(ans[i] == tempE)
            {
                return tempE;
            }
        }
        return (target-mini);
    }
};
