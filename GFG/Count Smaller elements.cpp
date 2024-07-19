#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &a) {
        int n = a.size();
        vector<int> ans(n);
        ordered_set s;
        for(int i=n-1;i>=0;i--){
            s.insert(a[i]);
            ans[i] = s.order_of_key(a[i]);
        }
        return ans;
    }
};
