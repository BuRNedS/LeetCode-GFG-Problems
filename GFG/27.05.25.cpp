class Solution {
  public:
    vector<int> leafNodes(vector<int>& preorder) {
        // code here
        queue<vector<int>>q;
        q.push(preorder);
        vector<int>ans;
        while(!q.empty())
        {
            vector<int>t=q.front();
            q.pop();
            vector<int>small;
            vector<int>large;
            if(t.size()==1)
            ans.push_back(t[0]);
            else
            {
                for(int i=1;i<t.size();i++)
                {
                    if(t[i]>t[0])
                    large.push_back(t[i]);
                    else
                    small.push_back(t[i]);
                    
                }
                if(!small.empty())
                q.push(small);
                if(!large.empty())
                q.push(large);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
