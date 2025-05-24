
class Solution {
  public:
    void subst(int n,int &sum)
    {
        sum+=n;
    }
    int sumSubstrings(string &s) {
        // code here
        int n = s.size();
        int sum=0;
        string g = "";
        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                for(int k=i; k<=j; k++)
                {
                    g.push_back(s[k]);
                }
                int x = stoi(g);
                subst(x,sum);
                g.clear();
            }
        }
        return sum;
    }
};
