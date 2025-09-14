class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        int totalGas = 0, totalCost = 0;
        
        for (int i = 0; i < n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        
        // If total gas is less than total cost, it's impossible
        if (totalGas < totalCost) return -1;
        
        int start = 0, tank = 0;
        for (int i = 0; i < n; i++) {
            tank += gas[i] - cost[i];
            
            // If tank goes negative, reset starting point
            if (tank < 0) {
                start = i + 1;
                tank = 0;
            }
        }
        return start;
    }
};
