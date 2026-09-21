class Solution {
public:
    int m, n;

    vector<pair<int, int>> directions = {{-1, 0},{1, 0},{0, -1},{0, 1}};

    vector<vector<int>> dp;

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans = max(ans, Agent(matrix, i, j));
            }
        }

        return ans;
    }

    int Agent(vector<vector<int>>& matrix, int i, int j) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int maxlen = 1;

        for (auto [dx, dy] : directions) {

            int ni = i + dx;
            int nj = j + dy;

            if (ni >= 0 && ni < m &&
                nj >= 0 && nj < n &&
                matrix[ni][nj] > matrix[i][j]) {

                maxlen = max(maxlen,
                             1 + Agent(matrix, ni, nj));
            }
        }

        return dp[i][j] = maxlen;
    }
};