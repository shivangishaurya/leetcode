class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,INT_MAX);
        if(n<=0)return 0;
        if(n==1)return 1;
        if(n==2)return 2;
        dp[0]=0;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            for(int j=1;j*j<=i;j++){
                dp[i]=min(dp[i],1+dp[i-j*j]);
            }
        }
        return dp[n];
    }
};