
class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        int a = 1, b = 1;
        priority_queue<pair<int, char>>q;
        for(int i = 0; i < n - 1; i++){
            q.push({y[i], 'h'});
        }
        for(int i = 0; i < m - 1; i++){
            q.push({x[i], 'v'});
        }
        int ans = 0;
        while(q.size()){
            auto t = q.top();
            q.pop();
            
            if(t.second == 'h'){
                ans += t.first * b;
                a += 1;
            }else{
                ans += t.first * a;
                b += 1;
            }
        }
        return ans;
    }
};
