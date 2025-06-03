int countSubstr(string &s, int k)
{
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> freq(26, 0);
        int distinct = 0;
        for (int j = i; j < s.size(); j++)
        {
            if (freq[s[j] - 'a'] == 0)
            {
                distinct++;
            }
            freq[s[j] - 'a']++;
            if (distinct == k)
            {
                count++;
            }
            if (distinct > k)
                break;
        }
    }
    return count;
}
