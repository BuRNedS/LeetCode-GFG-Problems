class Solution {
  public:
    // Function to find hIndex
    int hIndex(vector<int>&arr) {
        // code here
       int n=arr.size();
        vector<int>fre(n+1,0);
        for(int &i:arr){// filling the frequency leve
            if(i>=n)fre[n]++; //O(n)
            else fre[i]++;
 
                           }
int h =n;
int sum=0;
int ans=INT_MIN;

for(int i=n;i>=0;i--){//O(n)

if(sum+fre[i]>=i)ans=max(ans,i);
sum+=fre[i];

}

return ans;
//time O(n)+O(n);
// space O(n)

       
    }
};
