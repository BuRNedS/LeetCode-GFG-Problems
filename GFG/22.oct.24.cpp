
class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        // code here
        map<int,int>mp;
        mp[0]=1;
        int count=0,res=0;
        for(auto it:arr){
            if(it==x)count++;
            if(it==y)count--;
            if(mp[count])res+=mp[count];
            mp[count]+=1;
        }
        return res;
    }
};
