class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        const int n = deadline.size();
        int amount = 0, done = 0;
        
        vector<pair<int, int>> jobs;
        vector<int> spaces(n + 1);
        
        iota(spaces.begin(), spaces.end(), 0);
        
        for(int i = 0; i < n; i++) {
            jobs.push_back({profit[i], deadline[i]});
        }
        
        sort(jobs.begin(), jobs.end());
        
        auto can_fit = [&](auto can_fit, int dead) -> int {
            if(spaces[dead] == 0) return -1;
            if(spaces[dead] == dead) {
                return spaces[dead] = (dead - 1);
            }
            return spaces[dead] = can_fit(can_fit, spaces[dead]);
        }; 
        
        for(int i = n - 1; i >= 0; i--) {
            int val = jobs[i].first, dead = jobs[i].second;
            if(can_fit(can_fit, dead) != -1) {
                amount += val;
                done++;
            }
        }
     
        return {done, amount};
    }
};
