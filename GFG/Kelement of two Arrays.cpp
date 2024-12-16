int kthElement(vector<int>& a, vector<int>& b, int k) {
        
        for(int i=0,j=0;k>0;k--){
            if(k==1){
                if(j==b.size()) return a[i];
                if(i==a.size()) return b[j];
                return min(a[i], b[j]);
            }
            if(j==b.size() || (i<a.size() && a[i] < b[j])) i++;
            else j++;
        }
        return max(a.back(), b.back());
    }
