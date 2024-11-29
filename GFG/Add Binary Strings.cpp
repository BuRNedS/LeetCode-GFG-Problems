class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        string ans = "";  // To store the binary sum
        int i = s1.size() - 1;  // Pointer for `s1`
        int j = s2.size() - 1;  // Pointer for `s2`
        int carry = 0;  // Initialize carry

        // Process both strings until all bits are covered
        while (i >= 0 || j >= 0 || carry > 0) {
            int count1s = carry;  // Start with carry

            // Add 1 if the current bit of `s1` is '1'
            if (i >= 0 && s1[i] == '1') count1s++;

            // Add 1 if the current bit of `s2` is '1'
            if (j >= 0 && s2[j] == '1') count1s++;

            // Append the result bit to `ans`
            ans += (count1s % 2 == 0 ? '0' : '1');

            // Update carry
            carry = count1s / 2;

            // Move pointers to the next bit
            i--;
            j--;
        }
        // Reverse the result string to correct its order
        reverse(ans.begin(), ans.end());
        // To avoid leading zeros
        i=0;
        while(ans[i]=='0'){
            ans.erase(0,1);
         }
        return ans;
        }
   };
