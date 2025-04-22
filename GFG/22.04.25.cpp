int findUnique(vector<int> &arr) {

        // code here

        int ans=0;

        for(auto &ele: arr)

           ans ^= ele;

        return ans;

    }
