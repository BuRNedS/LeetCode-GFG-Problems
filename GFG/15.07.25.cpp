class Solution {
  public:
    bool divby13(string &s) {
        int rem=0;
        for(int i=0;i<s.length();i++){
            int dig=s[i]-'0';
            rem=(rem*10+dig)%13;
        }
        return rem==0;
    }
};
