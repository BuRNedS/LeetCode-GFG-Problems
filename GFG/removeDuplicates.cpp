vector<bool> s(26,false);
        for(int i=0;i<str.size();i++)
        {
             if(s[str[i]-'a']){
               str.erase(str.begin() + i);
               i--;
             }
             else
               s[str[i]-'a']=true;
            
        }
        return str;
