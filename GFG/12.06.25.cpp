class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n=arr.size();
        int index=-1;
        bool flag=true;
        int start=0,end=n-1;
        
        while(start<=end)
        {
            int mid=start+(end-start)/2;
            if(arr[mid]>=x)
            {
                index=mid;
                end=mid-1;
            }
            else
            start=mid+1;
        }
        int i,j;
        vector<int>ans;
        if(index==-1)
        {
            i=n-1;
            j=n;
        }
        else if(arr[index]==x)
        {
            i=index-1;
            j=index+1;
        }
        else
        {
            i=index-1;
            j=index;
        }
        
        while(k>0&&i>=0&&j<n)
        {
            if(x-arr[i]<arr[j]-x)
            {
                ans.push_back(arr[i]);
                i--;
            }
            else
            {
                ans.push_back(arr[j]);
                j++;
            }
            k--;
        }
        while(k>0&&i>=0)
        {
            ans.push_back(arr[i]);
            i--;
            k--;
        }
        while(k>0&&j<n)
        {
            ans.push_back(arr[j]);
            j++;
            k--;
        }
        
        return ans;
    }
};
