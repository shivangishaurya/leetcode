class Solution {
public:
    int solve(vector<int>& coins, int amount, int count, vector<int> & dp) {
        if (amount == 0)
            return count;
        if(dp[amount]!=-1)return dp[amount] == INT_MAX ? INT_MAX : count + dp[amount];
        int ans = INT_MAX;
        for (int i = 0; i < coins.size(); i++) {
            if (amount-coins[i] >= 0) {
                int a=solve(coins, amount-coins[i], count+1,dp);
                if(a!=INT_MAX)ans=min(ans,a);
            }
        }
         dp[amount] = (ans == INT_MAX) ? INT_MAX : ans - count;
        return ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>dp(amount+1,-1);
        int a=solve(coins,amount,0,dp);
        if(a!=INT_MAX)return a;
        return -1;
    }
};