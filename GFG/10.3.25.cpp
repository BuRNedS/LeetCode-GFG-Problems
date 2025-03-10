
class Solution {
public:
    int dp[1001][1001]; // Memoization table

    // Recursive function to calculate the minimum edit distance
    int solve(int i, int j, string& s1, string& s2) {
        // If we reach the end of s1, we need to insert remaining characters of s2
        if (i == s1.size()) return s2.size() - j;
        
        // If we reach the end of s2, we need to delete remaining characters of s1
        if (j == s2.size()) return s1.size() - i;

        // If already computed, return stored result
        if (dp[i][j] != -1) return dp[i][j];

        // If characters match, move to the next characters
        if (s1[i] == s2[j]) return dp[i][j] = solve(i + 1, j + 1, s1, s2);

        // Try all three operations and store the minimum cost
        int insert_op = 1 + solve(i, j + 1, s1, s2);   // Insert a character
        int delete_op = 1 + solve(i + 1, j, s1, s2);   // Delete a character
        int replace_op = 1 + solve(i + 1, j + 1, s1, s2); // Replace a character

        return dp[i][j] = min({insert_op, delete_op, replace_op});
    }

    // Main function to compute the edit distance
    int editDistance(string& s1, string& s2) {
        memset(dp, -1, sizeof(dp)); // Initialize dp table with -1
        return solve(0, 0, s1, s2);  // Start solving from index 0 of both strings
    }
};
