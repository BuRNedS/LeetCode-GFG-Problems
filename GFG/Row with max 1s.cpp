class Solution {
  public:
    int rowWithMax1s(vector<vector<int> > &arr) {
       // to store count of one's in each row
        int m=0;
        
        // for keep on stroing index;
        int idx=-1;
        // to store the idx no. if it has more no.of 1's then prevoius rows;
        int res=-1;
        
        for(vector<int> vec: arr){
         idx++;
         if( count(vec.begin(),vec.end(),1) > m){
             m=count(vec.begin(),vec.end(),1); res=idx;
         }
            
        }
        return res;
       
    }
};
