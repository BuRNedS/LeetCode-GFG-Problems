class Solution {
  public:
  // we created the bool to check
    bool ispossible(vector<int> &arr, int k,int mid)
    {
        int n=arr.size();
        int noofstudent=1; //here we denoted no of student to whom pages alloted at starting 
                            //it is only one;
        int pages=0;    //pages read=0;
        
        for(int i=0;i<arr.size();i++)
        {
            if(pages+arr[i]<=mid)   //we can add pages only when arr[i]+page is smaller than mid;
            {
                pages+=arr[i];      
            }
            else
            {
                noofstudent++; //if no more pages alloted than we will increase count of student;
                
                if(noofstudent>k || arr[i]>mid) //here this two condition need not to be 
                                                //statisfy if any of the condition statisfy
                {                               //return false
                    return false;
                }
                
                pages=arr[i];//also reset the pages according to new student
            }
        }
        return true;
    }
  
    int findPages(vector<int> &arr, int k) {
        if(arr.size()<k) //if arr.size<k then it will return -1 becouse it is not possible to allocate
                        //pages in k students
        return -1;
        
        
        int sum=0;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            sum+=arr[i];
        }
        int s=0;    //here count the number of pages which will start from 0 to total number of
        int e=sum;  //of pages here we denoted as sum;
        int ans=0;  
        while(s<=e) 
        {
            int mid=(s+e)/2;    //mid of total number of pages;
            
            if(ispossible(arr,k,mid)) //we use ispossibl function;
            {
                ans=mid; //if ispossible function is true then we denoted ans=mid
                e=mid-1;    //we put e=mid-1 because we find the max mid and now we try to
                            // find minimum mid if possible
            }
            else
            s=mid+1;    //if it it not possible then we do mid+1 by which page allocation increases
                        //and chance of find mid is also increase; 
        }
        return ans;
    }
};

