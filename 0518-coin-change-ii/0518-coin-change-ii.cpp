class Solution {
public:
    int solve(int amount,int index,vector<int> &coins,vector<vector<int>> & dp) {
        int n=coins.size();

        if (amount == 0)
            return 1;

        if(index==n)
            return 0;

        if(dp[index][amount]!=-1)
            return dp[index][amount];

    int ans=0;
    for(int i=index;i<n;i++){
        if(amount>=coins[i]){
            ans+=solve(amount-coins[i],i,coins,dp);
        }
    }
    return  dp[index][amount]=ans;
    }
        
    int change(int amount,vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return solve(amount,0,coins,dp);
    }
};