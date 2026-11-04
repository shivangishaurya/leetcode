
class Solution {
public:
    int rec(string& text1, string& text2, int i, int j,
            vector<vector<int>>& dp) {

        if (i >= text1.length() || j >= text2.length())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = 1 + rec(text1, text2, i + 1, j + 1, dp);
        }
        else {
            return dp[i][j] = max(
                rec(text1, text2, i, j + 1, dp),
                rec(text1, text2, i + 1, j, dp)
            );
        }
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length();
        int m = text2.length();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return rec(text1, text2, 0, 0, dp);
    }
};
