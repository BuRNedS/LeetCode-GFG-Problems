
int startStation(vector<int> &gas, vector<int> &cost) {
        // Your code here
        
        int totalgas = 0;
        int totalcost = 0;
        int currgas = 0;
        int start = 0;
        
        for(int i=0; i<gas.size(); i++)
        {
            totalgas += gas[i];
            totalcost += cost[i];
            
            currgas += gas[i] - cost[i];
            
            if(currgas < 0)
            {
                start = i + 1;
                currgas = 0;
            }
        }
        
        if(totalgas < totalcost)
            return -1;
        
        else
            return start;
    }
