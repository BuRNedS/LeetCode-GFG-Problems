int maximumProfit(vector<int> &p) {
        int n=p.size();
        int b=p[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(p[i]>=b){
                profit=max(profit,p[i]-b);
            }
            else{
                b=p[i];
            }
        }
        return profit;
    }
