class Solution {
  public:
    vector<int> minMaxCandy(vector<int>& prices, int k) {
        // Code here
        sort(prices.begin(),prices.end());
        int maxi =0;
        int mini = 0;
        int i = 0;
        int j = prices.size()-1;
        while(i<= j){
            
            mini += prices[i];
            j-= k;
            i++;
            
        }
        i = 0;
        j = prices.size()-1;
         while(i<= j){
            
            maxi += prices[j];
            i+= k;
            j--;
            
        }
        return {mini,maxi};
    }
