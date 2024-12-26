bool twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> u;
        for(int i:arr)
        {
            if(u.find(target-i)!=u.end())
            return true;
            else
            u[i]++;
        }
        return false;
}
