 bool pythagoreanTriplet(vector<int>& arr) {
        // code here
        int n=arr.size();
        int maxi=*max_element(arr.begin(),arr.end());
        vector<int>elements(maxi+1,0);
        for(int i:arr){
            elements[i]++;
        }
        
        for(int i=1;i<=maxi;i++){
            for(int j=i+1;j<=maxi;j++){
                // check if i and j exists in arr
                if(elements[i] && elements[j]){
                    int a=i,b=j;
                    int right=(a*a) + (b*b);
                    int c=sqrt(right);
                    if(c<=maxi && (c*c)==right && elements[c]) 
                        return true;
                }
            }
        }
        
        return false;
    }
