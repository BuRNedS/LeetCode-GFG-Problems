class Solution {
  public:
    // Function to determine if array arr can be split into three equal sum sets.
    vector<int> findSplit(vector<int>& arr) {
    
    
    int n=arr.size();
    
    int tsum=accumulate(arr.begin(),arr.end(),0);
    
    if(tsum%3!=0){
        
        return {-1,-1};
    }
    
int target=tsum/3;


int sum=0;

int i=-1;

int j=-1;

    for(int k=0;k<n;k++){
    

    sum=sum+arr[k];
    
    
    if(sum==target){
        
        i=k;
    }
    
       else if(sum==2*target){
           
           j=k;
           
           break;
       } 
     
        
    }
    
    return {i,j};
    }
};
