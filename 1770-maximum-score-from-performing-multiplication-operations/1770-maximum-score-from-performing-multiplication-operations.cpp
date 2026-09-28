class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size();
        int m=mul.size();
        vector<vector<int>>dp(m+1,vector<int>(m+1,0));
        for(int op=m-1;op>=0;op--){
            for(int l=0;l<=op;l++){
                int r=n-1-(op-l);
                int left= mul[op]*nums[l]+dp[op+1][l+1];
                int right=mul[op]*nums[r]+dp[op+1][l];
                dp[op][l]=max(left,right);
            }
        }
        return dp[0][0];
    }
};