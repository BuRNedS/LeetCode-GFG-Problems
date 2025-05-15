int n=s.length(),count=0, a[26]={0};
        for(int i=0;i<n;i++)
        {
            a[s[i]-'a']++;
            count+=a[s[i]-'a'];
        }
        return count;
