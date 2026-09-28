class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mul) {
        int n=nums.size();
        int m=mul.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,INT_MIN));
        return func(nums,mul,0,0,dp);
    }  
    int func(vector<int>& nums, vector<int>& mul,int op,int l,vector<vector<int>> & dp){
        if(op==mul.size()) return 0;
        if(dp[op][l]!=INT_MIN) return dp[op][l];
        int left=mul[op]*nums[l]+func(nums,mul,op+1,l+1,dp);
        int right=mul[op]*nums[nums.size()-1-(op-l)]+func(nums,mul,op+1,l,dp);
        return dp[op][l]=max(left,right);
    }
};