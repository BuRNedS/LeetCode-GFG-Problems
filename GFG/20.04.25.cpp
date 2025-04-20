int findDuplicate(vector<int>& arr) {

        int ans=0;

        for(int i=1;i<arr.size();i++)

            ans ^= i;

        for(auto &ele: arr)

            ans ^= ele;

        return ans;

    }
