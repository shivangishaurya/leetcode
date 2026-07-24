class Solution {
public:
    long long solve(int i, int k, int state,
                    vector<int>& prices,
                    vector<vector<vector<long long>>>& dp) {
        if (i == prices.size()) {
            if (state == 0)
                return 0;
            return LLONG_MIN / 2;
        }
        if (k == 0) {
            if (state == 0)
                return 0;
            return LLONG_MIN / 2;
        }
        if (dp[i][k][state] != LLONG_MIN)
            return dp[i][k][state];
        long long ans;
        if (state == 0) {
            long long skip =
                solve(i + 1, k, 0, prices, dp);
            long long buy =
                -1LL * prices[i] +
                solve(i + 1, k, 1, prices, dp);
            long long shortSell =
                1LL * prices[i] +
                solve(i + 1, k, 2, prices, dp);
            ans = max({skip, buy, shortSell});
        }
        else if (state == 1) {
            long long skip =
                solve(i + 1, k, 1, prices, dp);
            long long sell =
                1LL * prices[i] +
                solve(i + 1, k - 1, 0, prices, dp);
            ans = max(skip, sell);
        }
        else {
            long long skip =
                solve(i + 1, k, 2, prices, dp);
            long long buyBack =
                -1LL * prices[i] +
                solve(i + 1, k - 1, 0, prices, dp);
            ans = max(skip, buyBack);
        }
        return dp[i][k][state] = ans;
    }
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(k+1,vector<long long>(3, LLONG_MIN)));
        return solve(0, k, 0, prices, dp);
    }
};