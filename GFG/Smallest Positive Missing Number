class Solution{
    public:
    int missingNumber(int arr[], int n) { 
       sort(arr,arr+n);
       int count=1;
       for (int i=0;i<n;i++){
           if (arr[i]==count)
           count++;
       }
       return count;
    }
};
