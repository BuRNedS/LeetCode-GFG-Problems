int countStrings(String s) {
        // code here
        int n = s.length();
        int[] fre = new int[26];
        boolean flag = false;
        
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            fre[ch - 'a'] += 1;
            // If any of the char repeat, the original string will be also included in the ans
            if(fre[ch-'a'] >= 2) flag=true;
        }
        
        int ans = 1;
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            ans += n-i-fre[ch-'a'];
            fre[ch - 'a'] -= 1;
        }
        
        return flag?ans:ans-1;
    }
