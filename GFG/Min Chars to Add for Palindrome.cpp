class Solution {
public:
    int minChar(string& s) {
        int n = s.size();
        string rev_s = s; 
        reverse(rev_s.begin(), rev_s.end());

        string combined = s + '#' + rev_s; // Combine original string, separator, and reversed string
        int m = combined.size();

        // Compute the LPS (Longest Prefix Suffix) array
        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

        // Minimum characters to add
        return n - lps[m - 1];
    }
};
