class Solution {
  public:
    int minCost(vector<int>& arr) {
        priority_queue<int, vector<int>, greater<int>> pq(arr.begin(), arr.end());
        
        int cost = 0;
        
        while(!pq.empty()){
            int f = pq.top();pq.pop();
            if(pq.empty())break;
            int s = pq.top();pq.pop();
            pq.push(f+s);
            cost += f+s;
            
        }
        
        return cost;
    }
};
