string getMinSum(string first, string second)
    {
        string ans = "";
        
        reverse(first.begin(),first.end());
        reverse(second.begin(), second.end());
        
        int carry = 0;
        int sum = 0;
     
        int len_first = first.size(),  len_second = second.size();
        
        if(len_first > len_second)
        {
            swap(first,second);
        }
        int i = 0;
        for( ; i < first.size(); i++)
        {
            sum = (first[i] - '0') + (second[i] - '0') + carry;
            int digit = sum%10;
            carry = sum/10;
            ans += to_string(digit);
        }
        for( ; i < second.size(); i++)
        {
            sum = (second[i] - '0') + carry;
            int digit = sum%10;
            carry = sum/10;
            ans += to_string(digit);
        }
        if(carry)
            ans += to_string(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string minSum(vector<int> &arr)
    {
        string first = "";
        string second = "";
        vector<int> freq(10,0);
        for(int i = 0; i < arr.size(); i++)
        {
            freq[arr[i]]++;
        }
        bool flag = true;
        for(int i = 0; i < 10; i++)
        {
            while(freq[i] > 0)
            {
                if(flag)
                {
                    first += to_string(i);   
                    flag = !flag;
                }
                else
                {
                    second += to_string(i);
                    flag = !flag;
                }
                freq[i]--;
                    
            }
        }
           
        int count1 = 0, count2 = 0;
    
        for(int i = 0; i < first.size(); i++)
        {
            if(first[i] == '0')
                count1++;
        }
        for(int i = 0; i < second.size(); i++)
        {
            if(second[i] == '0')
                count2++;
        }
        if(count1 == first.size())
            first = to_string(0);
        else
            first = first.substr(count1);
            
        if(count2 == second.size())
            second = to_string(0);
        else
            second = second.substr(count2);
        
        
        return getMinSum(first,second);    
    }

