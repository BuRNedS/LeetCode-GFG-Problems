class Solution {
  public:
  int rcount=0;
  void merge(vector<int>&vec,int start,int mid,int end)
{
    int j = mid + 1;
    for (int i = start; i <= mid; i++) {
        while (j <= end && vec[i] > 2 * vec[j]) {
            j++;
        }
        rcount += (j - (mid + 1));
    }
int i=start;
j=mid+1;
vector<int>b;
while(i<=mid && j<=end)
{
if(vec[i]<=vec[j])
{
b.push_back(vec[i]);
i++;
}
else
{
b.push_back(vec[j]);
j++;
}
}
if(i<=mid)
{
while(i<=mid)
{
b.push_back(vec[i]);
i++;
}
}
else if(j<=end)
{
while(j<=end)
{
b.push_back(vec[j]);
j++;
}
}
int k=start;
for(int m=0; m<b.size(); m++)
{
vec[k]=b[m];
k++;
}
return;
}
  void merge_sort(vector<int>&vec,int start,int end)
{
if(start<end)
{
int mid=(start+end)/2;
merge_sort(vec,start,mid);
merge_sort(vec,mid+1,end);
merge(vec,start,mid,end);
}
else
{
return ;
}
}
    int countRevPairs(vector<int> &arr) {
        int n=arr.size();
        merge_sort(arr,0,n-1);
        return rcount;
    }
}; 
