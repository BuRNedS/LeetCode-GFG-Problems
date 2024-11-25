int maxProduct(vector<int> &arr) {
     int leftproduct=1,rightproduct=1;
     int ans=INT_MIN;
     for(int i=0;i<arr.size();i++)
     {
         leftproduct*=arr[i];
         rightproduct*=arr[arr.size()-1-i];
         ans=max({ans,leftproduct,rightproduct});
         if(leftproduct==0)
         {
             leftproduct=1;
         }
         if(rightproduct==0)
         {
             rightproduct=1;
         }
         
     }
     return ans;
    }
