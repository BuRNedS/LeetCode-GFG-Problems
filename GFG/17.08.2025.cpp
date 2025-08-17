class Solution {
  public:
    void rearrange(vector<int> &arr, int x) {
        // code here
        merge_sort(arr,x,0,arr.size()-1);
        
    }
    void merge_sort(vector<int> &a, int x, int left, int right) {
        if(left >= right) return;
        
        int mid = (left+right)/2;
        
        merge_sort(a,x,left, mid);
        merge_sort(a,x,mid+1, right);
        merge(a,x,left,mid,right);
    }
    void merge(vector<int> &a, int x, int left, int mid, int right) {
        int i, j;
        vector<int> v;
        
        for(i=left, j=mid+1; i<=mid && j<=right; ) {
            if(abs(x-a[i]) <= abs(x-a[j])) v.push_back(a[i++]);
            else v.push_back(a[j++]);
        }
        
        while(i<=mid) v.push_back(a[i++]);
        while(j<=right) v.push_back(a[j++]);
        
        for(i=left,j=0; i<=right; i++, j++) a[i] = v[j];
        
    }
};
