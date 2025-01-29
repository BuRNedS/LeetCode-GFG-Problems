double power(double b, int e) {
        // code here
        if(e==0)
            return 1;
        if(e==1)
            return b;
        if(e<0)
            return 1/power(b, -e);
            
        if(e%2==0)
            return power(b*b, e/2);
        return power(b, e-1)*b;
    }
